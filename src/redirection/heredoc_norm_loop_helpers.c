/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_norm_loop_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmtahmdabrahym <fatmtahmdabrahym@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by fatima            #+#    #+#             */
/*   Updated: 2025/10/20 19:00:00 by fatmtahmdab      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory.h"

bool    heredoc_handle_sigquit(void)
{
        if (get_signal_number() != SIGQUIT)
                return (false);
        clear_signal_number();
        return (true);
}

int     heredoc_update_iteration_state(int result, int *lines_read,
                bool *got_sigint)
{
        if (result == 1)
        {
                (*lines_read)++;
                return (1);
        }
        if (result == 3)
        {
                *got_sigint = true;
                return (3);
        }
        return (result);
}
