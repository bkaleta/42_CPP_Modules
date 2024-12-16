/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:30:03 by bkaleta           #+#    #+#             */
/*   Updated: 2024/12/16 17:18:42 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact 
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		Contact();
		void	setFirstName(const std::string &newFirstName);	
		void	setLastName(const std::string &newLastName);
		void	setNickname(const std::string &newNickname);
		void	setPhoneNumber(const std::string &newPhoneNumber);
		void	setDarkestSecret(const std::string &newDarkestSecret);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};