#include <iostream>
#include <vector>
#include <string>

using namespace std;

void readBinaryWatch(vector<int>& times, int time, int turnedOn, int lampNumber) {
    if(turnedOn == 0) {
        times.push_back(time);
        return;
    }

    if(turnedOn == lampNumber) {
        time += (1 << lampNumber) - 1;
        times.push_back(time);
        return;
    }

    readBinaryWatch(times, time, turnedOn, --lampNumber);
    readBinaryWatch(times, time + (1 << (lampNumber)), --turnedOn, lampNumber);
}

vector<string> readBinaryWatch(int turnedOn) {
    vector<string> timesFormatted;

    vector<int> times;
    readBinaryWatch(times, 0, turnedOn, 10);

    int n = times.size();
    for(int i = 0; i < n; ++i) {
        int hours = times[i] >> 6;
        int minutes = times[i] & 63;

        if(hours > 11 || minutes > 59) {
            continue;
        }

        string time = "";
        time += to_string(hours) + ':';
        if(minutes < 10) {
            time += '0';
        }
        time += to_string(minutes);

        timesFormatted.push_back(time);
    }

    return timesFormatted;
}

int main() {
    for(int i = 0; i < 11; ++i) {
        vector<string> times = readBinaryWatch(i);

        cout << "Number of lamps turned on: " << i << endl;
        cout << "Possible times: " << endl;
        for (const string& time : times) {
            cout << time << endl;
        }
        cout << endl;
    }

    return 0;
}
