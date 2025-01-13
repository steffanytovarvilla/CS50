#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name); // function to record a voter´s preference
void tabulate(void);                         // function to count votes for all remaining candidates
bool print_winner(void); // function to determine if any candidate has won the election
int find_min(void);      // function to fin the minimum vote total for candidates not yet eliminated
bool is_tie(int min);    // function to check if there is a tie among the remaining candidates
void eliminate(int min); // function to eliminate candidates who have the minimum number of votes

int main(int argc, string argv[])
{
    // Check for invalid usage
    // check if number of comandline arguments passed to program is more than 2, (no candidate names
    // provided). If this is the case, the program prints error
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        // Set name and initial votes for each candidate
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    // Get the number of voters
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            // Return false if the vote is invalid, otherwise return true
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        // Print a new line to separate the votes for each voter
        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    // Indicate successful completion of the program
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // name is a match with a name of a valid candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Update global preferences array to indicate voter has that candidate as their rank
            // preference
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
                break; // break out to continue tabulating or else, will only count one vote.
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // majority of votes = winner. Loop through and check if votes > half the count. if vote count >
    // half, then wins.
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Loop thru number of voters, thru candidates. If not eliminated and not lower tan minimum,
    // minimum becomes THAT value.
    int min = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // if still in election votes == min. If candidate eliminate = false, add 1 to eliminate, else
    // if equal min, ++.
    int eliminate = 0;
    int counter = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            eliminate++;
        }
        if (candidates[i].votes == min)
        {
            counter++;
        }
    }
    if (eliminate == counter)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Total vote count == min == eliminate.
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
