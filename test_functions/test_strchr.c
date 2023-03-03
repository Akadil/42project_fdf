/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:12:47 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/03 13:22:44 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hex_to_decimal(char* hex_string) {
    int decimal_value = 0;
    for (int i = 0; hex_string[i] != '\0'; i++) {
        char c = hex_string[i];
        int digit_value;
        if (c >= '0' && c <= '9') {
            digit_value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            digit_value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            digit_value = c - 'a' + 10;
        }
        decimal_value = decimal_value * 16 + digit_value;
    }
    return decimal_value;
}

int main(void)
{
    char    *name;

    name = "Akadil 0xff";
    printf("%d\n", hex_to_decimal(strchr(name, ' ') + 1));
    return (0);
}