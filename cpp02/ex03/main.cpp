/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:52:17 by jahlee            #+#    #+#             */
/*   Updated: 2023/07/24 21:02:51 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

int main( void ) {

	Point a;
	Point b(1.5f, 1.5f);
	a = b;
	std::cout << a.getXCoordinate() << " " << a.getYCoordinate() << std::endl;
	std::cout << b.getXCoordinate() << " " << b.getYCoordinate() << std::endl;
	return 0;
}