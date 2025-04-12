/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:34:57 by fgrabows          #+#    #+#             */
/*   Updated: 2025/04/12 17:04:59 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern& other);
  ~Intern();
  const Intern& operator=(const Intern& other);
  AForm* makeForm(std::string& formName, std::string& target);
};

#endif
