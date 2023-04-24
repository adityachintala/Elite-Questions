/*

The laser show at the Lumbini Park is something not to be missed.
But, as per govt rule they have to follow COVID-19 restrictions.
The management planning to guide the audience to sit in the seats
that maximizes the distance to the closest person, in order to
practice the social distance in the auditorium.

Please help usher to guide the audience to sit in a seat by following few rules:

- There are N seats in a single row, seats are numbered from 0 to N-1.
- Maximize the distance from person to the closest person.
- If there are multiple seats with similar distance, they sit in the seat with the lowest number.
- First person always sit in seat number 0.
- If a person leaves the auditorium from a seat, please consider that the seat is vacant

Create a class Auditorium and two functions in it.
1. int seat(): represent the seat number of audience to sit.
2. void leave(int s): person leaves the auditorium from a seat number 's'.

Input Format:
----------------
Line-1 -> two integers N and P, Number of seats N, Number of Operations P
P lines of input -> each line contains funtion number and parameter list (if required).

Output Format:
------------------
Print the alloted seat numbers in one line as output.


Sample Input-1:
-------------------
10 6
1
1
1
1
2 4
1

Sample Output-1:
---------------------
0 9 4 2 5

NOTE:
-----
In the sample input:
    - option 1 indicates, calling "int seat()" method.
    - option 2 indicates, calling "void leave(seat_num)" method.
    

*/

#include <bits/stdc++.h>
using namespace std;

class Auditorium {
private:
    int cnt;
    set<int> arr;
    int n;
public:
    Auditorium(int n) {
        this->n = n;
        cnt = 0;
    }
    
    int seat() {
        if (cnt == 0) {
            arr.insert(0);
            cnt++;
            return 0;
        } else {
            int m = INT_MIN;
            int inds = 0;
            int temps = 0;
            
            for (int i : arr) {
                if (m == INT_MIN) {
                    inds = -i+1;
                    m = i-1;
                    temps = i+1;
                } else {
                    if ((i-temps)/2-1+(i-temps)%2 > m) {
                        inds = temps;
                        m = (i-temps)/2-1+(i-temps)%2;
                    }
                    temps = i+1;
                }
            }
            int r = n;
            if ((r-temps-1) > m) {
                inds = temps;
                m = (r-temps-1);
            }
            int ind = m + inds;
            arr.insert(ind);
            cnt++;
            return ind;
        }
    }
    
    void leave(int p) {
        arr.erase(p);
        cnt--;
    }
};

int main() {
    int n, p;
    cin >> n >> p;
    Auditorium a(n);
    for (int i = 0; i < p; i++) {
        int num;
        cin >> num;
        if (num == 1) {
            int seatNum = a.seat();
            cout << seatNum << " ";
        } else {
            int seatNum;
            cin >> seatNum;
            a.leave(seatNum);
        }
    }
    return 0;
}