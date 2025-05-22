#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct Book {
    char title[100];
    char author[100];
    float price;
};

// Function to add book details to a file
void addBook() {
    FILE *file = fopen("books.txt", "a"); // Open file in append mode
    struct Book b;

    printf("Enter book title: ");
    scanf("\n%s", b.title); 
    printf("Enter author name: ");
    scanf("\n%s", b.author);
    printf("Enter price: ");
    scanf("%f", &b.price);

    fprintf(file, "%s\n%s\n%.2f\n", b.title, b.author, b.price); // Write to file
    fclose(file);
}

// Function to display book details from the file
void displayBooks() {
    FILE *file = fopen("books.txt", "r"); // Open file in read mode
    struct Book b;

    if (file == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\nSaved Book Records:\n");
    while (fscanf(file, " %s %s %f ", b.title, b.author, &b.price) != EOF) {
        printf("Title: %s Author: %s Price: %.2f\n", b.title, b.author, b.price);
    }
    fclose(file);
}

int main() {
    int choice;
    do {
        printf("\n1. Add Book \n2. View Books \n3. Exit \nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (1);

    return 0;
}