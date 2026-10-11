#include <stdio.h>
#include <string.h>

typedef struct {
    int roll;
    char name[30];
    float marks;
} Student;

void display(Student s[], int n) {
    printf("\nRoll\tName\tMarks\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
}

// 1. Linear Search
int linearSearch(Student s[], int n, int roll) {
    for (int i = 0; i < n; i++)
        if (s[i].roll == roll) return i;
    return -1;
}

// 2. Binary Search (Requires sorted array)
int binarySearch(Student s[], int n, int roll) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (s[mid].roll == roll) return mid;
        if (s[mid].roll < roll) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// 3. Selection Sort (by Roll)
void selectionSort(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (s[j].roll < s[min].roll) min = j;
        
        Student temp = s[i]; s[i] = s[min]; s[min] = temp;
    }
}

// 4. Selection Sort (Alphabetical by Name)
void selectionSortByName(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (strcmp(s[j].name, s[min].name) < 0) min = j;
        
        Student temp = s[i]; s[i] = s[min]; s[min] = temp;
    }
}

// 5. Insertion Sort (by Roll)
void insertionSort(Student s[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].roll > key.roll) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

// 6. Shell Sort (by Roll)
void shellSort(Student s[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Student temp = s[i];
            int j = i;
            while (j >= gap && s[j - gap].roll > temp.roll) {
                s[j] = s[j - gap];
                j -= gap;
            }
            s[j] = temp;
        }
    }
}

// 7. Insert (Simple Append) - returns new count
int insertRecord(Student s[], int n) {
    printf("Enter Roll, Name, Marks: ");
    scanf("%d %s %f", &s[n].roll, s[n].name, &s[n].marks);
    return n + 1; // Increment count
}

// 8. Delete (Swap with Last Element) - returns new count
int deleteRecord(Student s[], int n, int roll) {
    int pos = linearSearch(s, n, roll);
    if (pos == -1) {
        printf("Not found!\n");
        return n;
    }
    s[pos] = s[n - 1]; // Replace target with last element
    printf("Deleted!\n");
    return n - 1; // Decrement count
}

int main() {
    Student s[100];
    int n, choice, key, pos;

    printf("Enter number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Student %d (Roll Name Marks): ", i + 1);
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].marks);
    }

    while (1) {
        printf("\n1.Display 2.LinearSearch 3.BinarySearch 4.SelectSort(Roll) 5.SelectSort(Name) 6.InsertSort 7.ShellSort 8.Insert 9.Delete 10.Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) display(s, n);
        else if (choice == 2) {
            printf("Enter roll: "); scanf("%d", &key);
            pos = linearSearch(s, n, key);
            if (pos != -1) printf("Found at index %d\n", pos);
            else printf("Not found\n");
        }
        else if (choice == 3) {
            printf("Enter roll: "); scanf("%d", &key);
            pos = binarySearch(s, n, key);
            if (pos != -1) printf("Found at index %d\n", pos);
            else printf("Not found\n");
        }
        else if (choice == 4) { selectionSort(s, n); display(s, n); }
        else if (choice == 5) { selectionSortByName(s, n); display(s, n); }
        else if (choice == 6) { insertionSort(s, n); display(s, n); }
        else if (choice == 7) { shellSort(s, n); display(s, n); }
        else if (choice == 8) n = insertRecord(s, n);
        else if (choice == 9) {
            printf("Enter roll to delete: "); scanf("%d", &key);
            n = deleteRecord(s, n, key);
        }
        else if (choice == 10) break;
    }
    return 0;
}
