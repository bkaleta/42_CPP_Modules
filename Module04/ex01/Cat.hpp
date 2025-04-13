/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:59:03 by bkaleta           #+#    #+#             */
/*   Updated: 2025/04/13 21:58:28 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat :	public Animal
{
private:
	Brain	*brain;
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual	~Cat();

	virtual	void	makeSound() const;
	void setBrainIdea(int index, const std::string& idea);
    std::string getBrainIdea(int index) const;
	Brain *getBrainAddress() const;
};

#endif