#include "Rainbow.h"

 sf::Color Rainbow::Lerp(sf::Color A, sf::Color B, float Alpha){
	 return sf::Color(A.r + ((B.r - A.r) * Alpha), 
					A.g + ((B.g - A.g) * Alpha),
					A.b + ((B.b - A.b) * Alpha));
 }

size_t Rainbow::GetIndex(size_t idx){
    return idx % colors.size();
}