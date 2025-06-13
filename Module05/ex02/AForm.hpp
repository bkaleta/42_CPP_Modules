/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:16:29 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/13 12:52:21 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string 	_formName;
	bool				_formSigned;
	const int			_formGradeToSign;
	const int			_formGradeToExec;
public:
	AForm();
	AForm(const std::string &formName, const int formGradeToSign, const int formGradeToExec);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	~AForm();

	const std::string &getName() const;
	bool isSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExec() const;
	
	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Grade too high!");
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Grade too low!");
        }
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif