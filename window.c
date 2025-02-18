/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:38 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/18 20:34:29 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(void *param)
{
    (void)param;
    exit(0);
}

int key_hook(int keycode, void *param)
{
    (void)param;
    if (keycode == 65307)
        exit(0);
    return (0);
}

int open_ber(char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error: cannot open file\n", 24);
        return (-1);
    }
    return (fd);
}