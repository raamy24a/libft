/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:47:21 by radib             #+#    #+#             */
/*   Updated: 2025/04/22 13:32:38 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#include <stdlib.h>

static char **array_words_malloc(char const *s, char c)
{
    size_t words_count = 0;
    size_t i = 0;

    while (s[i]) {
        while (s[i] == c)
            i++;
        if (s[i] == '\0')
            break;
        words_count++;
        while (s[i] && s[i] != c)
            i++;
    }
    return malloc(sizeof(char *) * (words_count + 1));
}

static char **words_malloc(char const *s, char c, char **ptr_split)
{
    size_t i = 0;
    int words_count = 0;

    while (s[i]) {
        while (s[i] == c)
            i++;
        if (s[i] == '\0')
            break;
        size_t j = i;
        while (s[i] && s[i] != c)
            i++;
        ptr_split[words_count] = malloc(i - j + 1);
        if (!ptr_split[words_count]) {
            while (words_count--)
                free(ptr_split[words_count]);
            free(ptr_split);
            return NULL;
        }
        words_count++;
    }
    return ptr_split;
}

static char **ft_split_write(char const *s, char c, char **ptr_split)
{
    size_t words_count = 0;
    size_t i = 0;

    while (s[i]) {
        while (s[i] == c)
            i++;
        if (s[i] == '\0')
            break;
        size_t j = 0;
        while (s[i] && s[i] != c)
            ptr_split[words_count][j++] = s[i++];
        ptr_split[words_count++][j] = '\0';
    }
    ptr_split[words_count] = NULL;
    return ptr_split;
}

char **ft_split(char const *s, char c)
{
    char **ptr_split;

    if (!s)
        return NULL;
    ptr_split = array_words_malloc(s, c);
    if (!ptr_split)
        return NULL;
    if (!words_malloc(s, c, ptr_split)) {
        free(ptr_split);
        return NULL;
    }
    ft_split_write(s, c, ptr_split);
    return ptr_split;
}
