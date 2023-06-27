/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahlee <jahlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:31:23 by jahlee            #+#    #+#             */
/*   Updated: 2023/06/27 16:47:26 by jahlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "./includes.hpp"

class Contact
{
	private:
		std::string _contactInfo[5];
	public:
		std::string getContactInfo(eContact infoType);
		void setContactInfo(std::string str, eContact type);
		bool isValidContactInput(eContact type);
		void printContactNames(void);
		void printContactInfo(void);
};
#endif