class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // aisa kuch kr ki days and month ko 365 days mein likh sakun
        int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int arrival_month_alice = (arriveAlice[0] - '0')*10 + (arriveAlice[1] - '0');
        int arrival_date_alice = (arriveAlice[3] - '0')*10 + (arriveAlice[4] - '0');
        int leave_month_alice = (leaveAlice[0] - '0')*10 + (leaveAlice[1] - '0');
        int leave_date_alice = (leaveAlice[3] - '0')*10 + (leaveAlice[4] - '0');

        int arrival_month_bob = (arriveBob[0] - '0')*10 + (arriveBob[1] - '0');
        int arrival_date_bob = (arriveBob[3] - '0')*10 + (arriveBob[4] - '0');
        int leave_month_bob = (leaveBob[0] - '0')*10 + (leaveBob[1] - '0');
        int leave_date_bob = (leaveBob[3] - '0')*10 + (leaveBob[4] - '0');

        int arrive_alice = arrival_date_alice;
        for(int i = 0; i < arrival_month_alice - 1; i++) arrive_alice += arr[i];

        int leave_alice = leave_date_alice;
        for(int i = 0; i < leave_month_alice - 1; i++) leave_alice += arr[i];

        int arrive_bob = arrival_date_bob;
        for(int i = 0; i < arrival_month_bob - 1; i++) arrive_bob += arr[i];

        int leave_bob = leave_date_bob;
        for(int i = 0; i < leave_month_bob - 1; i++) leave_bob += arr[i];

        int start = max(arrive_alice, arrive_bob);
        int end = min(leave_alice, leave_bob);

        return max(0, end - start + 1);

    }
};