/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:26:47 by shagazi           #+#    #+#             */
/*   Updated: 2018/05/28 17:26:56 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
int main()
{
	// int x;
// 	int y;
// 	// wchar_t		c = L'\x82';
	wchar_t wz [3] = L"@@";
//
// 	// x = ft_printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");
// 	// x =  ft_printf("%C\n", L'à');
	int x = ft_printf("%ls\n", wz);
// 	// x += ft_printf("%C\n", L'ø');
// 	// x = ft_printf("|Kashim a %u histoires à raconter|\n", 1001);
// 	// x += ft_printf("|Il fait au moins %u|\n", -8000);
// 	// x += ft_printf("|%x|\n", -0);
// 	// x += ft_printf("|%o|\n", 0);
	printf("%d\n", x);
//
int y = ft_printf("%ls\n", wz);
// 	// y = printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");
//  	y = printf("%C\n", L'à');
	// printf("%ls\n", wz);
// 	// y = ft_printf("%C\n", c);
// 	// y += ft_printf("%C\n", L'ø');
// 	// y = printf("|Kashim a %u histoires à raconter|\n", 1001);
// 	// y += printf("|Il fait au moins %u|\n", -8000);
// 	// y += printf("|%x|\n", -0);
// 	// y += printf("|%o|\n", 0);
	printf("%d\n", y);

}
// 	int x = ft_printf("%D\n", -8000);
// 	printf("%d\n", x);
//
// 	int y = printf("%D\n", -8000);
// 	printf("%d\n", y);
// // 	ft_printf("% 4i", 42);
// 	ft_printf("% 4.5i\n", 42);
// 	ft_printf("% *.5i\n", 42);
// 	printf("% *.5i\n", 42);
/*
	  // ft_printf("@moulitest: %#.o %#.0o", 0, 0);
// 	  ft_printf("% 10.5d", 4242);
//   ft_printf("@moulitest: %#.x %#.0x", 0, 0);
  // // // // //
// 	ft_printf("%2c\n", 0);
// // // // 	ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
// // 	// ft_printf("% d\n", 42);
	// ft_printf("% d\n", -42);
// // 	ft_printf("% 10.5d\n", 4242);
// // 	ft_printf("% u\n", 4294967295);
// // 	printf("%2c\n", 0);
// // 	printf("@moulitest: %#.o %#.0o\n", 0, 0);
// // 	printf("% d\n", 42);
// // 	printf("% d\n", -42);
// // 	printf("% 10.5d\n", 4242);
// // 	printf("% u\n", 4294967295);
//
// // 	ft_printf("%+-0 5.6d\n", 42);
// // 	// ft_printf("%+-0 6.5d\n", 42);
// // 	printf("%+-0 5.6d\n", 42);
// // 	// printf("% 6.5d\n", 42);
// // 	// int x =   printf("Hash: %#o\n", 0);
// // 	// printf("%d\n", x);
// //   	// int y =   ft_printf("ftHash:%#o\n", 0);
// // 	// printf("%d\n", y);
// // 	// int z =   printf("Nohash: %o\n", 0);
// // 	// printf("%d\n", z);
// // 	// int a =   ft_printf("ftnohash: %o\n", 0);
// // 	// printf("%d\n", a);
// //
// // 	// int d = ft_printf("% 4.5i\n", 42);
// // 	// printf("%d\n", d);
// // 	// int e = printf("% 4.5i\n", 42);
// // 	// printf("%d\n", e);
// //   	return(0);*/
// }
