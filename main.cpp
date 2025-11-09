
#include "point.h"
#include "vector.h"
#include "utils.h"

int main() {
    float k, a;
    Print("       DONNEES:");
    
    /
    
    Point2f pA = MakeP2f(2.f, 4.f);
    Print("le point A est de coordonnees:", ToString(pA));

    
    Point2f pB = MakeP2f(3.f, 6.f);
    Print("le point B est de coordonnees:", ToString(pB));

    
    Vector2f v = MakeV2f(1.f, -1.f);
    Print("le vecteur V a pour coordonnees:", ToString(v));

    Vector2f w = MakeV2f(2.f, -3.f);
    Print("le vecteur W a pour coordonnees:", ToString(w));

    k = 5;
    Print("le rapport est k=:", ToString(k) );
    a = 90;
    Print("l'angle de la rotaion est a=:", ToString(a), "degre\n" );

   

    Print("=======OPERATIONS:===");

    Point2f r = Translate(pA, v);
    Print("1.la translation du point A par rapport au vecteur v est :", ToString(r));

    Point2f h = Scale(pA, k, k);
    Print("2.l'homothetie du point A par le rapport k est :", ToString(h));

    Point2f R = Rotate(pA, a);
    Print("3.les nouveaux coordonnees du point A apres la rotation d'angle a sont:", ToString(R));

    Vector2f s = Sub(v, w);
    Print("4.le resultat de la soustraction des vecteur V et W est:", ToString(s));

    Vector2f ad = Add(v, w);
    Print("5.le resultat de l'addition des vecteurs V et W est:", ToString(ad));

    float ps = Dot(v, w);
    Print("6.le produit scalaire de V et W est:", ToString(ps));

    Print("7.la norme du vecteur V est:", Length(v));

    float det = Determinant(v, w);
    Print("8.le determinant des vecteurs V et W est:", det);

    Vector2f AB = MakeV2f(pA, pB);
    Print("9.le vecteur creer a partir des points A et B est le vecteur AB:", ToString(AB));

     Vector2f n = Normalize(v);
     Print("la normalisation du vecteur V est :", ToString(n));

    return 0;
}
