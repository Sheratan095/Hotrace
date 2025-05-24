#include "../includes/Hotrace.h"

int insertion(t_data *data)
{
	char	*line;

	line = data->first_line;
	if (!line)
		line = get_next_line(0, FALSE);
	while (line && line[0] != '\n')
	{
		//
		free(line);
		line = get_next_line(0, FALSE);
	}
	if (line && line[0] == '\n')
	{
		line = get_next_line(0, FALSE);
		if (!line || line[0] == '\n')
			return (EXIT);
		data->first_line = line;
	}

}
