/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:49:15 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/07 17:02:32 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    int rows = 2;
    int cols = 3;
    
    // Allocate memory for the double array of struct instances
    struct Person **people = malloc(rows * sizeof(struct Person *));
    for (int i = 0; i < rows; i++) {
        people[i] = malloc(cols * sizeof(struct Person));
    }
    
    // Initialize the struct instances with data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sprintf(people[i][j].name, "Person %d%d", i+1, j+1);
            people[i][j].age = (i+1) * (j+1) * 10;
        }
    }
    
    // Access the struct instances and their data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Name: %s, Age: %d\n", people[i][j].name, people[i][j].age);
        }
    }
    
    // Free the memory
    for (int i = 0; i < rows; i++) {
        free(people[i]);
    }
    free(people);
    
    return 0;
}
