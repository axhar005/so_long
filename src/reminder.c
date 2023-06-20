// /// @brief calloc a 2d char array
// /// @param rows number of the array
// /// @param cols number of the array
// /// @return the array
// char	**allocate_2d_char_array(int32_t rows, int32_t cols)
// {
// 	int32_t	i;
// 	char	**arr;

// 	i = 0;
// 	arr = ft_calloc(cols + 1, sizeof(char *));
// 	while (i <= cols)
// 		arr[i++] = ft_calloc(rows + 1, sizeof(char));
// 	return (arr);
// }

// /// @brief print in terminal a 2d char array
// /// @param array the array
// void	print_2d_char_array(char **array)
// {
// 	int32_t	i;
// 	int32_t	j;

// 	i = 0;
// 	while (array[i])
// 	{
// 		j = 0;
// 		while (array[i][j])
// 			ft_printf("%c ", array[i][j++]);
// 		ft_printf("\n");
// 		i++;
// 	}
// }

// /// @brief fill a 2d char array with the letter c
// /// @param array to iterate
// /// @param rows number of the array
// /// @param cols number of the array
// /// @param c the letter use for fill
// void	fill_2d_char_array(char **array, int32_t rows, int32_t cols, char c)
// {
// 	int32_t	i;
// 	int32_t	j;

// 	i = 0;
// 	while (i <= cols)
// 	{
// 		j = 0;
// 		while (j <= rows)
// 			array[i][j++] = c;
// 		i++;
// 	}
// }


// #include "../inc/so_long.h"    

// bool (key_one_pressed(mlx, MLX_KEY))
// {
//     static buffer = true;

//     if (mlx_is_key_down(mlx, MLX_KEY))
//         if buffer == true {
//             buffer = false;
//             return true;
//         else
//             return false;
//     else
//         buffer = true;
//         return false;    
// }

// bool (key_one_pressed(mlx, MLX_KEY))
// {  
//     bool buffer = true;
//     while (mlx_is_key_down(mlx, key))
//         if buffer == true {
//             buffer = false
//             return true;
//         }
//         return false
// }




















