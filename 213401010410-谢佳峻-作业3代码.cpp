#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

typedef struct {
    char username[50];
    char password[50];
    int age;
} User;

void createUser(User users[], int *numUsers) {
    if (*numUsers < MAX_USERS) {
        User newUser;
        printf("Enter username: ");
        scanf("%s", newUser.username);
        printf("Enter password: ");
        scanf("%s", newUser.password);
        printf("Enter age: ");
        scanf("%d", &newUser.age);
        users[*numUsers] = newUser;
        (*numUsers)++;
        printf("User created successfully!\n");
    } else {
        printf("Maximum number of users reached.\n");
    }
}

void displayUser(User users[], int numUsers) {
    if (numUsers > 0) {
        int index;
        printf("Enter user index (0-%d): ", numUsers - 1);
        scanf("%d", &index);
        if (index >= 0 && index < numUsers) {
            printf("Username: %s\n", users[index].username);
            printf("Age: %d\n", users[index].age);
        } else {
            printf("Invalid index.\n");
        }
    } else {
        printf("No users created yet.\n");
    }
}

void loginUser(User users[], int numUsers) {
    char username[50];
    char password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return;
        }
    }
    printf("Login failed. Invalid username or password.\n");
}

void displayUserList(User users[], int numUsers) {
    if (numUsers > 0) {
        printf("User List:\n");
        for (int i = 0; i < numUsers; i++) {
            printf("%d. Username: %s, Age: %d\n", i, users[i].username, users[i].age);
        }
    } else {
        printf("No users created yet.\n");
    }
}

int main() {
    User users[MAX_USERS];
    int numUsers = 0;
    int choice;

    do {
        printf("\n1. Create new user\n");
        printf("2. Display user information\n");
        printf("3. Login\n");
        printf("4. Display user list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser(users, &numUsers);
                break;
            case 2:
                displayUser(users, numUsers);
                break;
            case 3:
                loginUser(users, numUsers);
                break;
            case 4:
                displayUserList(users, numUsers);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}