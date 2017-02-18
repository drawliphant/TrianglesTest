//
// Created by Stephen Clyde on 2/3/17.
//

#include "TriangleTester.h"

#include <iostream>
#include <cmath>

#include "../Triangle.h"
#include "../Utils.h"

void TriangleTester::testFirstConstructor()
{
    std::cout << "Execute TriangleTester::testConstructorWithStrings" << std::endl;

    Point** points = new Point*[3];
    points[0] = new Point(1,2,8);
    points[1] = new Point(3,1,4);
    points[2] = new Point(6,4,3);

    Triangle t(points);
    if (!t.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                 << t.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t.computerArea(), 9.35414, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                 << t.computerArea() << std::endl;
        return;
    }

    const Point* p = t.getPoint(0);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 0 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=1 || p->getY()!=2 || p->getZ()!=8)
    {
        std::cout << "Point 0 of triangle is not as expected, namely (1,2,8)" << std::endl;
        return;
    }

    p = t.getPoint(1);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=3 || p->getY()!=1 || p->getZ()!=4)
    {
        std::cout << "Point 1 of triangle is not as expected, namely (3,1,4)" << std::endl;
        return;
    }

    p = t.getPoint(2);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=6 || p->getY()!=4 || p->getZ()!=3)
    {
        std::cout << "Point 2 of triangle is not as expected, namely (6,4,3)" << std::endl;
        return;
    }
}

void TriangleTester::testSecondConstructor()
{
    std::cout << "Execute TriangleTester::testSecondConstructor" << std::endl;

    // TODO: Write representative test cases for the Triangle's second constructor

}

void TriangleTester::testEquilateralTriangles()
{
    std::cout << "Execute TriangleTester::testEquilateralTriangles" << std::endl;

    std::string triangleStr = "-10,0,0|10,0,0|0,17.32050808,0";
    Triangle t1(triangleStr);
    if (!t1.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType()!='E')
    {
        std::cout << "Triangle: unexpected type of "
                 << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t1.computerArea(), 173.205, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                 << t1.computerArea() << std::endl;
        return;
    }

    // TODO: Write additional representative test cases equilateral triangles
    std::string nString="-1,0,0|0,-1,0|0,0,-1";
    Triangle n(nString);
    if(n.getTriangleType()!='E'){
        std::cout<<"Traingle unexpectedly not Equalateral. Expecting: E Received: "<<n.getTriangleType()<<std::endl;
        std::cout<<"-1,0,0|0,-1,0|0,0,-1"<<std::endl;

    }
    if(!approximatelyEquals(n.computerArea(),0.866,0.001)){
        std::cout<<"Traingle calculated wrong area. Expecting: 0.866 Received: "<<n.computerArea()<<std::endl;
        std::cout<<"-1,0,0|0,-1,0|0,0,-1"<<std::endl;

    }
    if (!n.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!n.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }
}

void TriangleTester::testIsoscelesTriangles()
{
    std::cout << "Execute TriangleTester::testIsoscelesTriangles" << std::endl;
    std::string n="0,0,0|10,1,0|0,2,0";
    Triangle i(n);
    if(i.getTriangleType()!='I'){
        std::cout<<"Traingle unexpectedly not Equalateral. Expecting: I Received: "<<i.getTriangleType()<<std::endl;
        std::cout<<"0,0,0|10,1,0|0,2,0"<<std::endl;

    }
    if(!approximatelyEquals(i.computerArea(),10,0.001)){
        std::cout<<"Traingle calculated wrong area. Expecting: 10 Received: "<<i.computerArea()<<std::endl;
        std::cout<<"0,0,0|10,1,0|0,2,0"<<std::endl;

    }
    if (!i.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!i.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }
    // TODO: Write representative test cases isosceles triangles
}

void TriangleTester::testScaleneTriangles()
{
    std::cout << "Execute TriangleTester::testScaleneTriangles" << std::endl;
    std::string n="4,-2,13|9,7,24|-13,0,2";
    Triangle s(n);
    if(s.getTriangleType()!='S'){
        std::cout<<"Traingle unexpectedly not Scaline. Expecting: S Received: "<<s.getTriangleType()<<std::endl;
        std::cout<<"4,-2,13|9,7,24|-13,0,2"<<std::endl;

    }
    if(!approximatelyEquals(s.computerArea(),121.072,0.001)){
        std::cout<<"Traingle calculated wrong area. Expecting: 121.072 Received: "<<s.computerArea()<<std::endl;
        std::cout<<"4,-2,13|9,7,24|-13,0,2"<<std::endl;

    }
    if (!s.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!s.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    // TODO: Write representative test cases scalene triangles
}

void TriangleTester::testNonTriangles()
{
    std::cout << "Execute TriangleTester::testNonTriangles" << std::endl;
    std::string n="6,6,6|6,6,6|6,6,6";
    Triangle non(n);
    if(non.isTriangle()){
        std::cout<<"Not a triangle unexpectedly is a triangle 6,6,6|6,6,6|6,6,6"<<std::endl;
    }

    n="6,6,6|6,6,6|-6,-6,-6";
    Triangle no(n);
    if(no.isTriangle()){
        std::cout<<"Not a triangle unexpectedly is a triangle 6,6,6|6,6,6|-6,-6,-6"<<std::endl;
    }
    n="6,6,6|-6,-6,-6|-6,-6,-6";
    Triangle ne(n);
    if(ne.isTriangle()){
        std::cout<<"Not a triangle unexpectedly is a triangle 6,6,6|-6,-6,-6|-6,-6,-6"<<std::endl;
    }
    n="-6,-6,-6|6,6,6|-6,-6,-6";
    Triangle ni(n);
    if(ni.isTriangle()){
        std::cout<<"Not a triangle unexpectedly is a triangle -6,-6,-6|6,6,6|-6,-6,-6"<<std::endl;
    }
    // TODO: Write representative test cases non-triangles triangles
}

void TriangleTester::testInvalid()
{
    std::cout << "Execute TriangleTester::testInvalid" << std::endl;
    Point** points = new Point*[3];
    points[0] = new Point(INFINITY,0,0);
    points[1] = new Point(0,0,0);
    points[2] = new Point(0,0,0);
    Triangle ex(points);
    if(ex.isValid()){
        std::cout<<"Unexpected valid triangle, should be invalid x term"<<std::endl;
    }
    points[0] = new Point(0,0,0);
    points[1] = new Point(0,INFINITY,0);

    Triangle ey(points);
    if(ey.isValid()){
        std::cout<<"Unexpected valid triangle, should be invalid y term"<<std::endl;
    }
    points[2] = new Point(0,0,INFINITY);
    points[1] = new Point(0,0,0);

    Triangle ez(points);
    if(ez.isValid()){
        std::cout<<"Unexpected valid triangle, should be invalid z term"<<std::endl;
    }
    points[2] = new Point(0,0,0);
    Triangle e(points);
    if(!e.isValid()){
        std::cout<<"Unexpected invalid triangle, should be valid"<<std::endl;
    }
    // TODO: Write representative test cases invalid triangles
}
