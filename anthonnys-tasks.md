Architecture & Setup

- Set up the project file structure

- Write the main game loop (while week 1–7)

- Integrate everyone's functions into one working program

- Write the struct Question and struct GameState


---

Core Game Logic

- Write runAcademicQuiz() — load questions, score them, apply pass/fail penalties

- Write runJatiDiriQuiz() — same but with 80% threshold and stress multiplier

- Write checkStress() — branch into Counsellor or Healthy route

- Write endingEvaluator() — check all three conditions, trigger correct ending


---

Data & File Handling

- Write the question loader that reads from questions.dat

- Parse questions into Question arrays using ifstream and getline

- Handle file-not-found errors gracefully


---

Pointers & Memory

- Dynamic allocation for question option arrays (string*)

- Proper cleanup (delete[]) after each quiz module


---

STL Integration

- Use std::vector to store loaded questions

- Use std::map for subject name to question bank mapping


---

Polish & Final Assembly

- Integrate Faith's display functions into the correct game flow positions

- Write clearScreen() and scene transition logic

- Test all edge cases (stress = 50 exactly, all fail, all pass)

- Write the header comment block and all documentation

- Final compile, debug, and submission packaging
