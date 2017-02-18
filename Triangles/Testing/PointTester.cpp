//
// Created by Stephen Clyde on 2/3/17.
//

#include <iostream>
#include <cmath>
#include <limits>

#include "../Point.h"
#include "PointTester.h"

void PointTester::testConstructorWithDoubles()
{

    std::cout << "Execute PointTester::testConstructorWithDoubles" << std::endl;

    // Test 1st constructor by building 4 points
    Point p0(0,0,0);
    if (!p0.isValid() || p0.getX()!=0 || p0.getY()!=0 || p0.getZ()!=0)
    {
        std::cout << "Failure in constructing Point(0,0,0) isValid()="
                  << p0.isValid()
                  << " x=" << p0.getX()
                  << " y=" << p0.getY()
                  << " z=" << p0.getZ()
                  << std::endl;
        return;
    }

    Point p1(1,2,3);
    if (!p1.isValid() || p1.getX()!=1 || p1.getY()!=2 || p1.getZ()!=3)
    {
        std::cout << "Failure in constructing Point(0,0,0) isValid()="
                  << p1.isValid()
                  << " x=" << p1.getX()
                  << " y=" << p1.getY()
                  << " z=" << p1.getZ()
                  << std::endl;
        return;
    }

    Point p2(2.235,43.2,0);
    if (!p2.isValid() || p2.getX()!=2.235 || p2.getY()!=43.2 || p2.getZ()!=0)
    {
        std::cout << "Failure in constructing Point(0,0,0) isValid()="
                  << p1.isValid()
                  << " x=" << p1.getX()
                  << " y=" << p1.getY()
                  << " z=" << p1.getZ()
                  << std::endl;
        return;
    }

    Point p3(2.235,43.2,0.00001);
    if (!p3.isValid() || p3.getX()!=2.235 || p3.getY()!=43.2 || p3.getZ()!=0.00001)
    {
        std::cout << "Failure in constructing Point(0,0,0) isValid()="
                  << p3.isValid()
                  << " x=" << p3.getX()
                  << " y=" << p3.getY()
                  << " z=" << p3.getZ()
                  << std::endl;
        return;
    }

}

void PointTester::testIsEquivalentTo()
{
    std::cout << "Execute PointTester::testIsEquivalentTo" << std::endl;

    Point p0(0,0,0);
    Point p1(1,2,3);
    Point p2(2.235,43.2,0);
    Point p3(2.235,43.2,0.00001);

    // Test the equality of p0 with all four points
    if (!p0.isEquivalentTo(p0))
    {
        std::cout << "Failure in comparing p0 and p0 -- should be equal" << std::endl;
    }

    if (p0.isEquivalentTo(p1))
    {
        std::cout << "Failure in comparing p0 and p1 -- should not be equal" << std::endl;
    }

    if (p0.isEquivalentTo(p2))
    {
        std::cout << "Failure in comparing p0 and p2 -- should not be equal" << std::endl;
    }

    if (p0.isEquivalentTo(p3))
    {
        std::cout << "Failure in comparing p0 and p3 -- should not be equal" << std::endl;
    }

    // Test the equality of p1 with all four points
    if (p1.isEquivalentTo(p0))
    {
        std::cout << "Failure in comparing p1 and p0 -- should not be equal" << std::endl;
    }

    if (!p1.isEquivalentTo(p1))
    {
        std::cout << "Failure in comparing p1 and p1 -- should be equal" << std::endl;
    }

    if (p1.isEquivalentTo(p2))
    {
        std::cout << "Failure in comparing p1 and p2 -- should not be equal" << std::endl;
    }

    if (p1.isEquivalentTo(p3))
    {
        std::cout << "Failure in comparing p1 and p3 -- should not be equal" << std::endl;
    }

    // Test the equality of p2 with all four points
    if (p2.isEquivalentTo(p0))
    {
        std::cout << "Failure in comparing p2 and p0 -- should not be equal" << std::endl;
    }

    if (p2.isEquivalentTo(p1))
    {
        std::cout << "Failure in comparing p2 and p1 -- should not be equal" << std::endl;
    }

    if (!p2.isEquivalentTo(p2))
    {
        std::cout << "Failure in comparing p2 and p2 -- should be equal" << std::endl;
    }

    if (!p2.isEquivalentTo(p3))
    {
        std::cout << "Failure in comparing p2 and p3 -- should be equal" << std::endl;
    }

    // Test the equality of p3 with all four points
    if (p3.isEquivalentTo(p0))
    {
        std::cout << "Failure in comparing p3 and p0 -- should not be equal" << std::endl;
    }

    if (p3.isEquivalentTo(p1))
    {
        std::cout << "Failure in comparing p3 and p1 -- should not be equal" << std::endl;
    }

    if (!p3.isEquivalentTo(p2))
    {
        std::cout << "Failure in comparing p3 and p2 -- should be equal" << std::endl;
    }

    if (!p3.isEquivalentTo(p3))
    {
        std::cout << "Failure in comparing p3 and p3 -- should be equal" << std::endl;
    }

}

void PointTester::testConstructorWithStrings()
{
    std::cout << "Execute PointTester::testConstructorWithStrings" << std::endl;

    Point p0(0,0,0);
    Point p1(1,2,3);
    Point p2(2.235,43.2,0);
    Point p3(2.235,43.2,0.00001);

    // Test second constructor by creating for new points that should be the same as the previous four
    Point q0("0,0,0");
    if (!q0.isValid() || !q0.isEquivalentTo(p0))
    {
        std::cout << "Failure in constructing Point(\"0,0,0\") isValid()="
                  << q0.isValid()
                  << " x=" << q0.getX()
                  << " y=" << q0.getY()
                  << " z=" << q0.getZ()
                  << std::endl;
        //return;
    }

    // TODO: Write additional meaningful test cases for Point's string-based constructor
    Point b1("0.01,-.1,1");
    if(!b1.isValid()){
        std::cout<<"Failure in constructing Point(\"0.01,-.1,1\") isValid()="
                 << q0.isValid()
                 << " x=" << b1.getX()
                 << " y=" << b1.getY()
                 << " z=" << b1.getZ()
                 << std::endl;
    }
    Point b2("1a,.b,2.c");
    if(!b2.isValid()){
        std::cout<<"Failure in constructing Point(\"1a,.b,2.c\") Should be valid isValid()="
                 << b2.isValid()
                 << " x=" << b2.getX()
                 << " y=" << b2.getY()
                 << " z=" << b2.getZ()
                 << std::endl;
    }
}

void PointTester::testInvalid() {
    std::cout << "Execute PointTester::testInvalid" << std::endl;
    // TODO: Write meaningful test cases to check for invalid points
    Point a (0,0,0);
    Point b (-1000,1001,10);
    Point c (10,10,INFINITY);
    Point d (22, 44,std::numeric_limits<double>::max());
    if(!a.isValid()){
        std::cout<<"Point (0,0,0) Should be valid, isValid="<<a.isValid()<<std::endl;
    }
    if(!b.isValid()){
        std::cout<<"Point (-1000,1001,10) Should be valid, isValid="<<b.isValid()<<std::endl;
    }
    if(c.isValid()){
        std::cout<<"Point (10,10,INFINITY) Should not be valid, isValid="<<c.isValid()<<std::endl;
    }
    if(!d.isValid()){
        std::cout<<"Point (22, 44,std::numeric_limits<double>::max()) Should be valid, isValid="<<c.isValid()<<std::endl;
    }

}

