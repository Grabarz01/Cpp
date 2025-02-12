/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:06:11 by fgrabows          #+#    #+#             */
/*   Updated: 2025/02/12 10:47:46 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	
	void AddContact();
	void SearchContact() const;
private:
	Contact _contact[8];
	static int _nr_of_contacts;
	static int _indicatro;

	void PrintContact(void) const;
	
};