/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:19:44 by fgrabows          #+#    #+#             */
/*   Updated: 2025/06/23 18:50:39 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
 public:
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter& other);
  const ScalarConverter& operator=(const ScalarConverter& other);

  static void convert(const std::string& input);

 private:
  ScalarConverter();
};

#endif
