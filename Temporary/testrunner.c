#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userAuth.h"

#include <time.h>

typedef struct product {
    char name[50];
    float price;
    char description[100];
    struct product* next;
    struct product* prev;
} product;

void clearScreen() {
    system("cls"); 
}

void waitForKeypress() {
    printf("\nPress Enter to continue...");
    getchar();
}

void saveProductsToFile(product* head) {
    FILE* file = fopen("products.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    product* temp = head;
    while (temp != NULL) {
        fprintf(file, "%s\n", temp->name);
        fprintf(file, "%.2f\n", temp->price);
        fprintf(file, "%s\n", temp->description);
        temp = temp->next;
    }

    fclose(file);
}

product* readProductsFromFile() {
    FILE* file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    product* head = NULL;
    char name[50];
    float price;
    char description[100];

    while (fgets(name, sizeof(name), file) != NULL) {
        name[strcspn(name, "\n")] = '\0';  // Remove the newline character

        fscanf(file, "%f\n", &price);
        fgets(description, sizeof(description), file);
        description[strcspn(description, "\n")] = '\0';  // Remove the newline character

        product* newProduct = (product*)malloc(sizeof(product));
        strcpy(newProduct->name, name);
        newProduct->price = price;
        strcpy(newProduct->description, description);
        newProduct->next = NULL;
        newProduct->prev = NULL;

        if (head == NULL) {
            head = newProduct;
        } else {
            product* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newProduct;
            newProduct->prev = temp;
        }
    }

    fclose(file);
    return head;
}

product* createProduct() {
    char name[50];
    float price;
    char description[100];

    printf("Enter the product name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove the newline character

    printf("Enter the product price: ");
    scanf("%f", &price);
    fflush(stdin);

    printf("Enter the product description: ");
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = '\0';  // Remove the newline character

    product* newProduct = (product*)malloc(sizeof(product));
    strcpy(newProduct->name, name);
    newProduct->price = price;
    strcpy(newProduct->description, description);
    newProduct->next = NULL;
    newProduct->prev = NULL;

    return newProduct;
}

void addProduct(product** headPtr) {
    product* newProduct = createProduct();

    if (*headPtr == NULL) {
        *headPtr = newProduct;
    } else {
        newProduct->next = *headPtr;
        (*headPtr)->prev = newProduct;
        *headPtr = newProduct;
    }

    printf("Product added successfully.\n\n");
    waitForKeypress();
}

void deleteProduct(product** headPtr) {
    if (*headPtr == NULL) {
        printf("No products to delete.\n\n");
        waitForKeypress();
        return;
    }

    char name[50];
    printf("Enter the name of the product to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove the newline character

    product* current = *headPtr;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current == *headPtr) {
                *headPtr = current->next;
                if (*headPtr != NULL)
                    (*headPtr)->prev = NULL;
            } else {
                current->prev->next = current->next;
                if (current->next != NULL)
                    current->next->prev = current->prev;
            }

            free(current);
            printf("Product deleted successfully.\n\n");
            waitForKeypress();
            return;
        }

        current = current->next;
    }

    printf("Product not found.\n\n");
    waitForKeypress();
}

// Display the product list
void displayProducts(product* head) {
if (head == NULL) {
printf("No products to display.\n");
return;
}
printf("Product List:\n");
printf("--------------------------------------------------------\n");
printf("%-20s %-10s %-40s\n", "Name", "Price", "Description");
printf("--------------------------------------------------------\n");

product* temp = head;
while (temp != NULL) {
    printf("%-20s $%.2f   %-40s\n", temp->name, temp->price, temp->description);
    temp = temp->next;
}

printf("--------------------------------------------------------\n");
waitForKeypress();
}

void viewCart(char* cartFile) {
    FILE* file = fopen(cartFile, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[100];
    printf("Cart:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

product* merge(product* left, product* right) {
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    product* result = NULL;

    if (left->price <= right->price) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}




void split(product* head, product** left, product** right) {
    if (head == NULL || head->next == NULL) {
        *left = head;
        *right = NULL;
        return;
    }

    product* slow = head;
    product* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

void mergeSort(product** headPtr) {
    product* head = *headPtr;
    product* left = NULL;
    product* right = NULL;

    if (head == NULL || head->next == NULL)
        return;

    split(head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *headPtr = merge(left, right);
}

void buyProduct(product* head, char* cartFile) {
    if (head == NULL) {
        printf("No products to buy.\n\n");
        waitForKeypress();
        return;
    }

    char name[50];
    printf("Enter the name of the product to buy: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove the newline character

    product* current = head;
    product* selectedProduct = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            selectedProduct = current;
            break;
        }

        current = current->next;
    }

    if (selectedProduct == NULL) {
        printf("Product not found.\n\n");
        waitForKeypress();
        return;
    }

    FILE* file = fopen(cartFile, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        waitForKeypress();
        return;
    }

    fprintf(file, "Product Name: %s\n", selectedProduct->name);
    fprintf(file, "Price: %.2f\n", selectedProduct->price);
    fprintf(file, "Description: %s\n", selectedProduct->description);
    fprintf(file, "---------------------------------\n");

    fclose(file);

    printf("Product added to cart.\n\n");

    // Calculate and print the bill
    float total = selectedProduct->price;
    printf("\nBill:\n");
    printf("Product Name: %s\n", selectedProduct->name);
    printf("Price: %.2f\n", selectedProduct->price);
    printf("---------------------------------\n");
    printf("Total: %.2f\n", total);
    printf("---------------------------------\n\n");

    waitForKeypress();
}

void displayCart(char* cartFile) {
    FILE* file = fopen(cartFile, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        waitForKeypress();
        return;
    }

    char line[100];
    printf("Cart:\n");
    if (fgets(line, sizeof(line), file) == NULL) {
        printf("Cart is empty.\n");
    } else {
        printf("%s", line);
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }
    }

    fclose(file);
    waitForKeypress();
}



void freeProducts(product* head) {
    product* current = head;
    while (current != NULL) {
        product* temp = current;
        current = current->next;
        free(temp);
    }
}

void saveOrderDetails(char* cartFile, char* orderFile) {
    FILE* cart = fopen(cartFile, "r");
    if (cart == NULL) {
        printf("Error opening cart file.\n");
        waitForKeypress();
        return;
    }

    FILE* order = fopen(orderFile, "a");
    if (order == NULL) {
        printf("Error opening order file.\n");
        fclose(cart);
        waitForKeypress();
        return;
    }

    char line[100];
    time_t currentTime;
    time(&currentTime);
    fprintf(order, "Order Details - Date: %s", ctime(&currentTime));
    while (fgets(line, sizeof(line), cart) != NULL) {
        fprintf(order, "%s", line);
    }

    fclose(cart);
    fclose(order);

    // Clear the cart file
    cart = fopen(cartFile, "w");
    if (cart == NULL) {
        printf("Error clearing cart file.\n");
        waitForKeypress();
        return;
    }
    fclose(cart);

    printf("Order details saved.\n");
    printf("Cart cleared.\n\n");
    waitForKeypress();
}

void printBill(const char* cartFile) {
    FILE* file = fopen(cartFile, "r");
    if (file == NULL) {
        printf("Error opening cart file.\n");
        waitForKeypress();
        return;
    }

    clearScreen();
    printf("Bill:\n");
    printf("=============================================\n");

    double total = 0.0; // Variable to store the total amount

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);

        // Assuming the line format is "<item> <price>"
        char item[50];
        double price;
        if (sscanf(line, "%s %lf", item, &price) == 2) {
            total += price;
        }
    }

    printf("=============================================\n");
    printf("Total: %.2f\n", total); // Print the total amount
    fclose(file);
    waitForKeypress();
}

void viewOrderHistory(char* orderFile) {
    FILE* file = fopen(orderFile, "r");
    if (file == NULL) {
        printf("No order history available.\n\n");
        waitForKeypress();
        return;
    }

    char line[100];
    printf("Order History:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
    waitForKeypress();
}

void admintOptions() {
    product* head = NULL;
    int choice;
    head = readProductsFromFile();
    char cartFile[] = "cart.txt";
    char orderFile[] = "order.txt";

    do {
        clearScreen();
        printf("Welcome Admin\n");
        printf("Menu:\n");
        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. Display Products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                printf("Add Product\n");
                printf("-----------\n");
                addProduct(&head);
                saveProductsToFile(head);
                break;
            case 2:
                deleteProduct(&head);
                saveProductsToFile(head);
                break;
            case 3:
            fflush(stdin);
                displayProducts(head);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                waitForKeypress();
                break;
        }
    } while (choice != 4);
}

void customerOptions() {
    product* head = NULL;
    int choice;
    char username[50];

    printf("Enter your Name: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';
    head = readProductsFromFile();

    char cartFile[100];
    char orderFile[100];

    snprintf(cartFile, sizeof(cartFile), "%s_cart.txt", username);
    snprintf(orderFile, sizeof(orderFile), "%s_order.txt", username);
    do {
        printf("Customer Options:\n");
        printf("1. Display Products\n");
        printf("2. Sort and Display Products\n");
        printf("3. Buy Product\n");
        printf("4. View Cart\n");
        printf("5. Print Bill\n");
        printf("6. Save Order Details\n");
        printf("7. View order history\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                displayProducts(head);
                break;
                case 2:
                mergeSort(&head);
                displayProducts(head);
                break;
            case 3:
                buyProduct(head, cartFile);
                break;
            case 4:
                displayCart(cartFile);
                break;
            case 5:
                printBill(cartFile);
                break;
            case 6:
                saveOrderDetails(cartFile, orderFile);
                break;
            case 7:
                viewOrderHistory(orderFile);
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 8);

    freeProducts(head);
}

int main() {
    int role;
    int choice;

    do {
        clearScreen();
        printf("\t\t\tWelcome to the Online Store\n");
        printf("\t\t\tMenu:\n");
        printf("\t\t\t1. Admin\n");
        printf("\t\t\t2. Customer\n");
        printf("\t\t\t3. Exit\n");
        printf("\t\t\tEnter your role: ");
        scanf("%d", &role);


        fflush(stdin);

        switch (role) {
            case 1:
                admintOptions();
                break;
            case 2:
                if(userLoginMenu())
                fflush(stdin);
                customerOptions();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid role. Please try again.\n\n");
                waitForKeypress();
                break;
        }
    } while (role != 3);

    return 0;
}
