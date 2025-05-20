/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:16 by bkaleta           #+#    #+#             */
/*   Updated: 2025/05/20 19:01:34 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
protected:
	const std::string 	_name;
	int					_grade;
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	bool GradeTooHighException();
	bool GradeTooLowException();
	void getName();
	void getGrade();
	void incrementGrade();
	void decrementGrade();
};

#endif 