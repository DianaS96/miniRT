/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coverand <coverand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:14:09 by coverand          #+#    #+#             */
/*   Updated: 2022/07/06 19:53:52 by coverand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_clear(t_scene **scene)
{
	t_list	*tmp;

	tmp = NULL;
	if (*scene)
	{
		if ((*scene)->cams)
			free((*scene)->cams);
		if ((*scene)->ambient)
			free((*scene)->ambient);
		if ((*scene)->light)
			free((*scene)->light);
		if ((*scene)->elements)
		{
			while ((*scene)->elements)
			{
				free(((t_object *)((*scene)->elements->content))->ptr);
				free(((t_object *)((*scene)->elements->content)));
				tmp = (*scene)->elements;
				(*scene)->elements = (*scene)->elements->next;
				free(tmp);
			}			
		}
		free(*scene);
	}
}
