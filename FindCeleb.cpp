
/*
Solution 1: Create an indegrees and outdegrees array.
For each element check if indegrees == N-1 an doutgerees = 0
Time Complexity: O(V*V), V = Number of people/vertices
Space Complexity: O(V), V = Number of people/vertices

////////////////////////////////////////////////////////////

Solution 2: Assume person 0 is the celeb and keep updating it with other persons.
Check if other people know the potential Celeb and if the potentialCeleb knows nobody.
Time Complexity: O(V),  V = Number of people/vertices
Space Complexity: O(1)

*/
class Solution {
public:
    int findCelebrity(int n) {
        int indegress[n];
        int outdegres[n];
        for ( int i = 0; i < n; i++){
            indegress[i] = 0;
            outdegres[i] = 0;
        }
        for ( int i =0; i < n ; i++){
            for ( int j =0; j< n ; j++){
                if( i != j){
                    if ( knows(i, j)){
                        indegress[j] += 1;
                        outdegres[i] += 1;
                    }
                }
                
            }        
        }
        
        for ( int i =0; i < n ; i++){
            if ( indegress[i] == n-1 and outdegres[i]== 0 ) return i;
        }
        return -1;
    }
};
//////////////////////////////



class Solution {
public:
    int findCelebrity(int n) {
        int potentialCeleb = 0;
        for (int i = 1; i < n; i++){
            if ( knows(potentialCeleb, i)){
                potentialCeleb = i;
            }
        }
        
        for (int i = 0; i < n; i++){
            if ( i == potentialCeleb) continue;
            if ( knows(potentialCeleb, i) or !knows(i, potentialCeleb)){
                return -1;
            }
        }
        return potentialCeleb;
    }
};