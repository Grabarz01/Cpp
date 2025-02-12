/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:25:20 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/03 19:22:34 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	Weapon &_weapon;
	std::string _name;
	HumanA(void);

public:
	HumanA(std::string name, Weapon& weapon);
	void attack(void);
};

#endif 
