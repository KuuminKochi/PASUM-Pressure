# PASUM Pressure! - Beginner Programming Tasks
**For: Faith Law Lyk Tong | FAC1003 Programming 2**

---

## Before You Start

Make sure you have:
- A C++ compiler installed (ask Anthonny if unsure)
- A code editor (VS Code is recommended)
- The main project file open so you can see how things connect

These tasks are **self-contained** — each one is a separate small function
that Anthonny will plug into the main game. You don't need to understand
the whole project to complete these.

**How to test your work:** Run your code separately in a new `.cpp` file
first before handing it over.

---

## Task P1 — Display a Progress Bar

### What it does
Shows the player a visual bar representing their current score or stress
level. Like this:
Stress Level: [████████░░░░░░░░░░░░] 40%

### What you need to know
- `for` loops
- `cout`
- Basic `if` statements

### Instructions
1. Create a function called `displayBar`
2. It takes in two things: a `label` (text) and a `percentage` (number 0–100)
3. Print the label first
4. Use a `for` loop that runs 20 times
5. If the current position is less than `percentage / 5`, print `█`
6. Otherwise print `░`
7. After the loop, print the percentage number with a `%` sign

### Expected Output
Academic Score: [████████████░░░░░░░░] 60%
Stress Level:   [████░░░░░░░░░░░░░░░░] 20%

### Starting Point
```cpp
#include <iostream>
#include <string>
using namespace std;

void displayBar(string label, int percentage) {
    // your code here
}

int main() {
    displayBar("Academic Score:", 60);
    displayBar("Stress Level:  ", 20);
    return 0;
}
```

---

## Task P2 — Display the Score Summary Screen

What it does


At the end of each week, show the player a neat summary of all

their current scores. Like this:


	╔══════════════════════════════╗
	║       END OF WEEK 3          ║
	╠══════════════════════════════╣
	║  Academic Score  :  60       ║
	║  Jati Diri Score :  80       ║
	║  Stress Level    :  45       ║
	╚══════════════════════════════╝

What you need to know

- cout

- Function parameters

- Basic string formatting

Instructions

1. Create a function called displayWeekSummary

2. It takes in four things: week, academic, jatiDiri, stress

3. Print a decorative box using ═, ║, ╔, ╗, ╚, ╝, ╠, ╣

(copy-paste these symbols — they're just characters)

4. Display each score neatly inside the box

5. Add a line at the bottom that says either:
	- "Keep it up!" if stress is below 50

	- "Take a breather..." if stress is 50 or above


Expected Output

	╔══════════════════════════════╗
	║       END OF WEEK 3          ║
	╠══════════════════════════════╣
	║  Academic Score  :  60       ║
	║  Jati Diri Score :  80       ║
	║  Stress Level    :  45       ║
	╠══════════════════════════════╣
	║  Keep it up!                 ║
	╚══════════════════════════════╝

Starting Point

	#include <iostream>
	using namespace std;
	
	void displayWeekSummary(int week, int academic, int jatiDiri, int stress) {
	    // your code here
	}
	
	int main() {
	    displayWeekSummary(3, 60, 80, 45);
	    return 0;
	}


---

## Task P3 — Input Validation Function

What it does


Makes sure the player only enters a valid answer (e.g. 1, 2, 3, or 4).

If they type something wrong, it keeps asking until they get it right.


	Choose your answer (1-4): 9
	Invalid input. Please enter a number between 1 and 4.
	Choose your answer (1-4): abc
	Invalid input. Please enter a number between 1 and 4.
	Choose your answer (1-4): 2

What you need to know

- while loops

- cin

- Basic if statements

Instructions

1. Create a function called getValidInput

2. It takes in two things: min and max (the allowed range)

3. Ask the player to enter a number

4. If what they typed is not a number OR is outside the range,

print an error and ask again

5. Once valid, return the number they entered

Hints

- Use cin >> choice to read input

- Use cin.fail() to check if they typed something that isn't a number

- After a bad input, use cin.clear() and

cin.ignore(1000, '\n') to reset

Starting Point

	#include <iostream>
	using namespace std;
	
	int getValidInput(int min, int max) {
	    int choice;
	    // your code here
	    return choice;
	}
	
	int main() {
	    cout << "Choose your answer (1-4): ";
	    int answer = getValidInput(1, 4);
	    cout << "You chose: " << answer << endl;
	    return 0;
	}


---

## Task P4 — Subject Selection Menu

What it does


Shows the player a menu to choose their academic quiz subject

and returns their choice.


	╔══════════════════════════════╗
	║    Choose Your Subject       ║
	╠══════════════════════════════╣
	║  1. Chemistry                ║
	║  2. Physics                  ║
	║  3. Mathematics              ║
	╚══════════════════════════════╝
	Enter your choice (1-3):

What you need to know

- cout

- switch or if-else

- Functions

Instructions

1. Create a function called displaySubjectMenu

2. Print the menu box shown above

3. Call getValidInput(1, 3) to get the player's choice

(you can copy your function from Task P3, or just use cin for now)

4. Use a switch statement to print a confirmation message:
	- 1 → "You chose Chemistry. Good luck!"

	- 2 → "You chose Physics. Good luck!"

	- 3 → "You chose Mathematics. Good luck!"


5. Return the choice as an int

Expected Output

	╔══════════════════════════════╗
	║    Choose Your Subject       ║
	╠══════════════════════════════╣
	║  1. Chemistry                ║
	║  2. Physics                  ║
	║  3. Mathematics              ║
	╚══════════════════════════════╝
	Enter your choice (1-3): 2
	You chose Physics. Good luck!

Starting Point

	#include <iostream>
	using namespace std;
	
	int displaySubjectMenu() {
	    int choice;
	    // your code here
	    return choice;
	}
	
	int main() {
	    int subject = displaySubjectMenu();
	    return 0;
	}


---

## Task P5 — Display a Single Quiz Question

What it does


Takes a question and its four answer choices, displays them nicely,

and returns which option the player picked.


	----------------------------------------
	Q3. What is the pH of pure water?
	
	  1) 5
	  2) 7
	  3) 9
	  4) 14
	
	Your answer (1-4):

What you need to know

- cout

- string arrays

- Function parameters

Instructions

1. Create a function called displayQuestion

2. It takes in:
	- questionNumber (int) — e.g. 3

	- questionText (string) — the question itself

	- options (string array of 4 items) — the four choices


3. Print the question number and text

4. Use a for loop to print each option numbered 1 to 4

5. Ask the player for their answer

6. Use getValidInput(1, 4) or plain cin to get their choice

7. Return the choice as an int

Expected Output

	----------------------------------------
	Q3. What is the pH of pure water?
	
	  1) 5
	  2) 7
	  3) 9
	  4) 14
	
	Your answer (1-4): 2

Starting Point
```cpp
	#include <iostream>
	#include <string>
	using namespace std;
	
	int displayQuestion(int questionNumber,
	                    string questionText,
	                    string options[4]) {
	    // your code here
	    return 0;
	}
	
	int main() {
	    string opts[4] = {"5", "7", "9", "14"};
	    int answer = displayQuestion(3, "What is the pH of pure water?", opts);
	    cout << "Player answered option: " << answer << endl;
	    return 0;
	}
```

