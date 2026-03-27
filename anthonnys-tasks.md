# PASUM Pressure! - Developer Task Checklist
**For: Anthonny Ng Hon Wei | FAC1003 Programming 2**

---

## Architecture & Setup

- [x] Set up project file structure (`main.cpp`, `questions.dat`, `story.txt`)
- [x] Define `struct Question` with `string* options` pointer array
- [x] Define `struct GameState` with `week`, `academic`, `jatiDiri`, `stress`
- [x] Write `main()` entry point with `while` game loop (week 1–7)
- [x] Write `initializeGame()` to set all starting values

---

## Core Game Logic

- [x] Write `runAcademicQuiz()` — score questions, apply +10 academic or +10 stress
- [x] Write `runJatiDiriQuiz()` — score questions, apply `stress *= 1.2` if < 80%
- [x] Write `checkStress()` — branch into Counsellor or Healthy route at threshold 50
- [x] Write `displayStory(int week)` — pull and display correct week narrative
- [x] Write `displayInterlude()` — display interlude text between quiz sections
- [x] Write `endingEvaluator()` — check all three conditions, trigger correct ending


---

## Integration (Faith's Functions)

- [x] Plug `displayBar()` into weekly summary and stress check screens
- [x] Plug `displayWeekSummary()` at the end of each week loop iteration
- [x] Plug `getValidInput()` into all answer reading sections
- [x] Plug `displaySubjectMenu()` into academic quiz subject selection
- [x] Plug `displayQuestion()` into both quiz modules

---

## Polish & Final Assembly

- [x] Write `clearScreen()` for scene transitions
- [x] Test edge case — stress exactly 50.0
- [x] Test edge case — all academic quizzes failed
- [x] Test edge case — all quizzes passed perfectly
- [x] Test edge case — non-numeric and out-of-range inputs
- [x] Write header comment block (author, date, description, instructions)
- [x] Write inline comments for all calculation logic
- [ ] Write function comments (purpose, parameters, return value)
- [x] Final compile with zero warnings
- [ ] Package and submit via team leader before 3 April 2026

---

## Submission Checklist

- [ ] All source files compiling cleanly
- [ ] Coding Proposal document completed
- [ ] Problems from Sem 1 section written
- [ ] Submitted to https://forms.gle/GkyxQm3FaVWCDJLn6 by Week 14

---

*Document prepared by: Anthonny Ng Hon Wei*
*Last updated: March 2026*
