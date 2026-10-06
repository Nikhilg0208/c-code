#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int startTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
};

void calculateFCFS(vector<Process> &processes) {
    int n = processes.size();
    if (n == 0) return;

    // Sort processes by arrival time (if same arrival time, sort by process ID)
    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b) {
        if (a.arrivalTime == b.arrivalTime)
            return a.id < b.id;
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;
    float totalTAT = 0;
    float totalWT = 0;

    for (int i = 0; i < n; i++) {
        // If CPU is idle before current process arrives
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        processes[i].startTime = currentTime;
        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        processes[i].responseTime = processes[i].startTime - processes[i].arrivalTime;

        currentTime = processes[i].completionTime;

        totalTAT += processes[i].turnaroundTime;
        totalWT += processes[i].waitingTime;
    }

    // Display Process Table
    cout << "\n=========================================================================\n";
    cout << " PID | Arrival | Burst | Start | Completion | Turnaround | Waiting | Response\n";
    cout << "=========================================================================\n";
    for (const auto &p : processes) {
        cout << setw(4) << p.id << " | "
             << setw(7) << p.arrivalTime << " | "
             << setw(5) << p.burstTime << " | "
             << setw(5) << p.startTime << " | "
             << setw(10) << p.completionTime << " | "
             << setw(10) << p.turnaroundTime << " | "
             << setw(7) << p.waitingTime << " | "
             << setw(8) << p.responseTime << "\n";
    }
    cout << "=========================================================================\n";

    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time (TAT) : " << (totalTAT / n) << " ms";
    cout << "\nAverage Waiting Time (WT)       : " << (totalWT / n) << " ms\n\n";

    // Gantt Chart Visualization
    cout << "Gantt Chart:\n";
    cout << "+";
    for (const auto &p : processes) {
        cout << "------P" << p.id << "------+";
    }
    cout << "\n0";
    for (const auto &p : processes) {
        cout << setw(14) << p.completionTime;
    }
    cout << "\n\n";
}

int main() {
    // Sample processes: {Process ID, Arrival Time, Burst Time}
    vector<Process> processes = {
        {1, 0, 4},
        {2, 1, 3},
        {3, 2, 1},
        {4, 3, 2},
        {5, 4, 5}
    };

    cout << "--- First-Come, First-Served (FCFS) CPU Scheduling ---\n";
    calculateFCFS(processes);

    return 0;
}
