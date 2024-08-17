/* 
ExhaustiveSolve
---------------
This is the "not-very-smart" version of a cryptarithmetic solver.
It takes the puzzle itself (with the 3 strings for the two addends and sum)
and a string of letters as yet unassigned. If no more letters to assign,
then we've hit a base-case. If the current letter-to-digit mapping solves
the puzzle, we're done. Otherwise, we return False to trigger backtracking.
If we have letters to assign, we take the first letter from that list and
try assigning it the digits from 0 to 9 and then recursively work
through solving the puzzle from here. If we manage to make a good assignment
that works, we've succeeded. Otherwise, we need to unassign that choice and try
another digit. This version is easy to write since it uses a simple
approach (quite similar to permutations if you think about it), but it is
not so smart because it doesn't take into account the structure of the
puzzle constraints (for example, once the two digits for the addends have
been assigned, there is no reason to try anything other than the correct
digit for the sum), yet it tries a lot of useless combos regardless.
*/

bool exhaustive_solve(Puzzle& puzzle, std::string letters_to_assign) {
    if (letters_to_assign.empty()) {  // no more choices to make
        return puzzle_solved(puzzle);  // checks arithmetic to see if it works
    }
    for (int digit = 0; digit < 10; ++digit) {  // try all digits
        if (assign_letter_to_digit(letters_to_assign[0], digit)) {
            if (exhaustive_solve(puzzle, letters_to_assign.substr(1))) {
                return true;
            }
            unassign_letter_from_digit(letters_to_assign[0], digit);
        }
    }
    return false;  // nothing worked, need to backtrack
}
