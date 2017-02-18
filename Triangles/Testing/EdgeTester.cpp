//
// Created by Stephen Clyde on 2/3/17.
//

#include "EdgeTester.h"

#include <iostream>
#include <cmath>
#include "../Point.h"
#include "../Edge.h"

void EdgeTester::testEdge01()
{
    std::cout << "Execute EdgeTester::testEdge01" << std::endl;

    Point p0(0,0,0);
    Point p1(1,0,0);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (e.getLength()!=1)
    {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 1)"
                  << std::endl;
        return;
    }

    if (e.getSlopeX()!=INFINITY)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting INFINITY)"
                  << std::endl;
        return;
    }

    if (e.getSlopeY()!=0)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0)"
                  << std::endl;
        return;
    }

    if (e.getSlopeZ()!=0)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 0)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testEdge02()
{
    std::cout << "Execute EdgeTester::testEdge02" << std::endl;

    Point p0(1,0,0);
    Point p1(3,4,5);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (fabs(e.getLength() - 6.708203932) > 0.001)
    {
        std::cout << "Failure in e.getLength(), length="
                  << e.getLength() << " (expecting 6.708203932)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeX() - 0.312347524) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting 0.312347524)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeY() - 0.742781353) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0.742781353)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeZ() - 1.118033989) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 1.118033989)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testParallelEdges()
{
    std::cout << "Execute EdgeTester::testParallelEdges" << std::endl;
    Point a1 (10,0,0);
    Point a2 (0,0,0);
    Point b1 (10,0,10);
    Point b2 (0,0,10);
    Edge a(&a1,&a2);
    Edge b(&b1,&b2);

    // TODO: Writing a representative set of test cases for edges that are parallel with other
    if(!a.isParallelTo(b)){
        std::cout<<"Failure to calculate parallel slope. Should be parallel. a.isParallelTo(b)="<<a.isParallelTo(b)
                 <<" lines 10,0,0|0,0,0 and 10,0,10|0,0,10"<<std::endl;
    }
    Point c1(-2,-5,9);
    Point c2(0,0,0);
    Point d1(1,1,1);
    Point d2(-1,-4,10);

    Edge c(&c1,&c2);
    Edge d(&d1,&d2);
    if(c.isParallelTo(d)){

        std::cout<<"Failure to calculate parallel slope. Shouldnt be parallel. c.isParallelTo(d)="<<c.isParallelTo(d)
                 <<" lines -2,-5,9|0,0,0 and 1,1,1|-1,-4,10"<<std::endl;

    }
    Edge e(&c1,&c2);
    Edge f(&c2,&c1);
    if(e.isParallelTo(f)){

        std::cout<<"Failure to calculate parallel slope. Shouldnt be parallel. c.isParallelTo(d)="<<c.isParallelTo(d)
                 <<" lines -2,-5,9|0,0,0 and 0,0,0|-2,-5,9"<<std::endl;

    }
}

void EdgeTester::testNonParallelEdges()
{
    std::cout << "Execute EdgeTester::testNonParallelEdges" << std::endl;
    Point a1 (10,0,0);
    Point a2 (0,0,0);
    Point b1 (10,0,10);
    Point b2 (0,0,10);
    Edge a(&a1,&b2);
    Edge b(&b1,&a2);

    // TODO: Writing a representative set of test cases for edges that are parallel with other
    if(a.isParallelTo(b)){
        std::cout<<"Failure to calculate parallel slope. Should not be parallel. a.isParallelTo(b)="<<a.isParallelTo(b)
                 <<" lines 10,0,0|0,0,0 and 10,0,0|0,0,10"<<std::endl;
    }
    Point c1(-2,-5,9);
    Point c2(0,0,0);
    Point d1(1,1,1);
    Point d2(-1,-4,10);

    Edge c(&c1,&d2);
    Edge d(&d1,&c2);
    if(c.isParallelTo(d)){

        std::cout<<"Failure to calculate parallel slope. Should not be parallel. a.isParallelTo(b)="<<c.isParallelTo(d)
                 <<" lines -2,-5,9|0,0,0 and 1,1,1|-1,-4,10"<<std::endl;

    }
}

void EdgeTester::testNonLengthEdges()
{
    std::cout << "Execute EdgeTester::testNonLengthEdges" << std::endl;
    Point p1(1,1,1);

    Point p2(-100,10,1);
    Point p3(0,1,1);
    Point p4(1,0,1);
    Point p5(1,1,0);
    Edge n(&p2,&p2);
    Edge g(&p1,&p1);
    Edge x(&p3,&p1);
    Edge y(&p4,&p1);
    Edge z(&p5,&p1);

    // TODO: Writing a representative set of test cases for edges have a length of zero or approximately zero
    if(n.getLength()!=0){
        std::cout<<"Failure to calculate length of zero length edge. Points (1,1,1),(1,1,1). Calculated length= "<<n.getLength()<<std::endl;
    }
    if(g.getLength()!=0){
        std::cout<<"Failure to calculate length of zero length edge. Points (-100,10,1),(-100,10,1). Calculated length= "<<n.getLength()<<std::endl;
    }
    if(x.getLength()==0){
        std::cout<<"Failure to calculate length of 1 length edge. Points (0,1,1),(1,1,1). Calculated length= "<<x.getLength()<<std::endl;
    }
    if(y.getLength()==0){
        std::cout<<"Failure to calculate length of 1 length edge. Points (1,0,1),(1,1,1). Calculated length= "<<y.getLength()<<std::endl;
    }
    if(z.getLength()==0){
        std::cout<<"Failure to calculate length of 1 length edge. Points (1,1,0),(1,1,1). Calculated length= "<<z.getLength()<<std::endl;
    }

}

void EdgeTester::testBadEdges()
{
    std::cout << "Execute EdgeTester ::testBadEdges" << std::endl;
    Point* bad=NULL;
    Point* ex=new Point(INFINITY,-10,3);
    Point* why=new Point(0,INFINITY,-1);
    Point* zed=new Point(-5,4,INFINITY);
    Point* good=new Point(-1,2,37);
    // TODO: Writing a representative set of test cases for edges not formed correctly
    Edge a(bad,good);
    Edge b(good,bad);
    Edge c(why,bad);
    Edge d(zed,bad);
    Edge e(bad,bad);
    Edge f(bad,ex);
    if(a.isValid()){
        std::cout<<"Unexpected valid edge. isValid()="<<a.isValid()<<std::endl;
    }
    if(b.isValid()){
        std::cout<<"Unexpected valid edge. isValid()="<<b.isValid()<<std::endl;
    }
    if(c.isValid()){
        std::cout<<"Unexpected valid edge. isValid()="<<c.isValid()<<std::endl;
    }
    if(d.isValid()){
        std::cout<<"Unexpected valid edge. isValid()="<<d.isValid()<<std::endl;
    }
    if(e.isValid()){
        std::cout<<"Unexpected valid edge. isValid()="<<e.isValid()<<std::endl;
    }
    if(f.isValid()){
        std::cout<<"Unexpected valid edge. isValid()="<<f.isValid()<<std::endl;
    }

}
