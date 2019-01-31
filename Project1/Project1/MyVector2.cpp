//Aaron O Neill
#include "MyVector2.h"

/// <summary>
/// get length of vector using sqrt of the sum of the squares
/// </summary>
/// <param name="t_vector">input vector</param>
/// <returns>length</returns>
float vectorLength(sf::Vector2f t_vector)
{//start function
	float sumOfSquares = vectorLengthSquared(t_vector); // function call to get the length squared
	const float length = sqrt(sumOfSquares); // get the length by using sqrt on the length squared
	return length; //return value
}//end function

///gets the length of the vector squared
float vectorLengthSquared(sf::Vector2f t_Vector)
{//start function
	float lengthSquared = (t_Vector.x * t_Vector.x) + (t_Vector.y * t_Vector.y); // formula to get the length squared
	return lengthSquared; //returns value
}//end function

///gets the cross product of two vectors
float vectorCorssProduct(sf::Vector2f t_VectorA, sf::Vector2f t_VectorB)
{//Start function
	float value{ 0 }; //variable for calculations
	value = ((t_VectorA.x * t_VectorB.x) - (t_VectorA.y * t_VectorB.y)); //calculation for vector cross product
	return value; //return value
}//End function

///gets the dot product of two vectors
float vectorDotProduct(sf::Vector2f t_vectorA, sf::Vector2f t_VectorB)
{//start function
	float dotProduct = (t_vectorA.x * t_VectorB.x) + (t_vectorA.y * t_VectorB.y); //calculation for the dot product of two vectors
	return dotProduct;
}//end function

///gets the angle between two vectors
float vectorAngleBetween(sf::Vector2f t_VectorA, sf::Vector2f t_VectorB)
{//start function
	float angle{ 0 }; //angle between the two vectors
	float dotProduct{ 0 }; // dot product of the two vectors used in the function
	float magnitudeProduct{ 0 }; // dot product of the magnitude of the two vectors
	dotProduct = vectorDotProduct(t_VectorA, t_VectorB); //gets the dot product of the two vectors
	magnitudeProduct = ((vectorLength(t_VectorA)) * (vectorLength(t_VectorB))); //gets the product of the two vectors
	angle = radiansToDegree(acos(dotProduct / magnitudeProduct)); // caluclation for the angle between two vectors
	return angle;//returns the angle between the vectors
}//end function

///function that rotates a vector by a given degree
sf::Vector2f vectorRotateBy(sf::Vector2f t_vector, float t_angleRadians)
{//start function
	float px{ 0 }; // variable to store new x value, used so the calculation isnt corrupted
	float py{ 0 }; // variable to store new Y value
	px = (t_vector.x * cos(t_angleRadians)) - (t_vector.y * sin(t_angleRadians)); //rotates the x point by the given angle
	py = (t_vector.y  * sin(t_angleRadians)) + (t_vector.x * sin(t_angleRadians)); // rotated the y point by the given angle
	sf::Vector2f answer{ px , py }; //creates the new vector with the two new points
	return answer; //returns new vector
}//end function

///function that projects a vector onto another vector
sf::Vector2f vectorProjection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{// start function
	float dotProduct{ 0 }; //used in the calculation
	sf::Vector2f projection{ 0.0f,0.0f }; //used to store answer
	dotProduct = vectorDotProduct(t_vector, t_onto); // gets the dot product of the vector and vector it goes onto
	projection = (dotProduct / (vectorLengthSquared(t_onto))) * t_onto; // calculation to get the projection
	return projection; //returns the vector
}// end function

///function that gets the rejection of a vector onto another vector
sf::Vector2f vectorRejection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{ // start function
	sf::Vector2f rejection{ 0.0f,0.0f };// initialise vector that needs to be returned
	rejection = t_vector - vectorProjection(t_vector, t_onto); //calculation for rejection
	return rejection; //returns rejection
}// end function

float vectorScalarProjection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	float scalarProjection{ 0 };
	scalarProjection = vectorLength(vectorProjection(t_vector, t_onto));
	return scalarProjection;
}

sf::Vector2f vectorUnitVector(sf::Vector2f t_vector)
{
	sf::Vector2f unitVector = t_vector / vectorLength(t_vector);
	return unitVector;
}

//used for conversions to simplify
float degreeToRadians(float t_degree)
{
	float radians{ 0 }; //variable to store radians
	radians = t_degree * PI / 180; //conversion from degree to radians
	return radians;
}

float radiansToDegree(float t_radians)
{
	float degree{ 0 }; // variable to store degree
	degree = t_radians * 180 / PI; //conversion from radians to degree
	return degree;
}
