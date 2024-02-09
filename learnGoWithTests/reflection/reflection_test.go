package reflection

import (
	"reflect"
	"testing"
)

type Person struct {
	Name    string
	Profile Profile
}

type Profile struct {
	Age  int
	City string
}

func TestMatch(t *testing.T) {
	t.Run("first test", func(t *testing.T) {
		got := Match("10.0.0.0/8", "10.151.96.10")
		want := true

		if got != want {
			t.Errorf("want %t got %t", want, got)
		}
	})
	t.Run("second test", func(t *testing.T) {
		got := Match("10.0.0.0/8", "127.0.0.1")
		want := false

		if got != want {
			t.Errorf("want %t got %t", want, got)
		}
	})
}

func TestWalk(t *testing.T) {
	cases := []struct {
		Name          string
		Input         interface{}
		ExpectedCalls []string
	}{
		{
			"struct with one string field",
			struct {
				Name string
			}{"Chris"},
			[]string{"Chris"},
		},
		{
			"struct with two string fields",
			struct {
				Name string
				City string
			}{"Chris", "Moscow"},
			[]string{"Chris", "Moscow"},
		},
		{
			"struct with non string field",
			struct {
				Name string
				Age  int
			}{"Chris", 33},
			[]string{"Chris"},
		},
		{
			"nested fiels",
			Person{"Chris", Profile{33, "London"}},
			[]string{"Chris", "London"},
		},
		{
			"pointers to things",
			&Person{"Chris", Profile{33, "London"}},
			[]string{"Chris", "London"},
		},
		{
			"slices",
			[]Profile{
				{33, "London"},
				{34, "Moscow"},
			},
			[]string{"London", "Moscow"},
		},
		{
			"arrays",
			[2]Profile{
				{33, "London"},
				{34, "Moscow"},
			},
			[]string{"London", "Moscow"},
		},
	}

	for _, test := range cases {
		t.Run(test.Name, func(t *testing.T) {
			var got []string
			walk(test.Input, func(input string) {
				got = append(got, input)
			})

			want := test.ExpectedCalls
			if !reflect.DeepEqual(got, want) {
				t.Errorf("got %v want %v", got, want)
			}
		})
	}
	t.Run("with maps", func(t *testing.T) {
		aMap := map[string]string{
			"Cow":   "Moo",
			"Sheep": "Baa",
		}

		var got []string
		walk(aMap, func(input string) {
			got = append(got, input)
		})

		assertContains(t, got, "Moo")
		assertContains(t, got, "Baa")
	})
	t.Run("with channels", func(t *testing.T) {
		aChannel := make(chan Profile)

		go func() {
			aChannel <- Profile{33, "Moscow"}
			aChannel <- Profile{34, "Astana"}
			close(aChannel)
		}()

		var got []string
		want := []string{"Moscow", "Astana"}
		walk(aChannel, func(input string) {
			got = append(got, input)
		})

		if !reflect.DeepEqual(got, want) {
			t.Errorf("got %v want %v", got, want)
		}
	})
	t.Run("with func", func(t *testing.T) {
		aFunc := func() (Profile, Profile) {
			return Profile{33, "Moscow"}, Profile{34, "Astana"}
		}

		var got []string
		want := []string{"Moscow", "Astana"}
		walk(aFunc, func(input string) {
			got = append(got, input)
		})

		if !reflect.DeepEqual(got, want) {
			t.Errorf("got %v want %v", got, want)
		}
	})
}

func assertContains(t testing.TB, got []string, s string) {
	t.Helper()
	contains := false
	for _, x := range got {
		if x == s {
			contains = true
		}
	}

	if !contains {
		t.Errorf("expected %v to conatin %q but it didn't", got, s)
	}
}
