*NOM: YOUBISSI NGATCHEUSSI DAVID

*MATRICULE: 25P921

# GEOMETRY_HOMEWORK
Devoir de programmation modulaire de géométrie
## **📐 MATH - Bibliothèque de Géométrie 2D**

### **📖 Description du Projet**

**MATH** est une bibliothèque C++ éducative implémentant les concepts fondamentaux de la géométrie 2D à travers des structures de points et de vecteurs. Ce projet démontre l'utilisation des **struct** en C++ pour modéliser des concepts mathématiques.

### **🏗️ Structures et Fonctions**

#### **Structures de Données Simples**
```cpp
struct Point2f { float x, y; };    // Point dans l'espace 2D
struct Vector2f { float x, y; };   // Vecteur 2D avec direction et magnitude
```

#### **Fonctions Principales Points 2D**
- **`MakeP2f(x, y)`** - Crée un point aux coordonnées spécifiées
- **`MakeNullPoint()`** - Retourne le point origine (0, 0)
- **`Translate(point, dx, dy)`** - Déplace un point selon un delta
- **`Scale(point, sx, sy)`** - Redimensionne par rapport à l'origine
- **`Rotate(point, angle)`** - Rotation autour de l'origine
- **`Egal(a, b, tolerance)`** - Compare deux points avec précision

#### **Fonctions Principales Vecteurs 2D**
- **`MakeV2f(x, y)`** - Crée un vecteur depuis des composantes
- **`MakeNullVector()`** - Retourne le vecteur nul
- **`MakeV2f(pointA, pointB)`** - Vecteur entre deux points
- **`Add(a, b)`** - Addition vectorielle
- **`Dot(a, b)`** - Produit scalaire
- **`Normalize(v)`** - Normalise un vecteur
- **`Lerp(a, b, t)`** - Interpolation linéaire

---

## **📁 FICHIERS DU PROJET**

### **📄 geometry/point.h**
```cpp
#ifndef POINT_H
#define POINT_H

#include <string>

// Déclaration anticipée pour éviter l'inclusion circulaire
struct Vector2f;

struct Point2f {
    float x;
    float y;
};

// Création et manipulation de points
Point2f MakeP2f(float x, float y);
Point2f MakeNullPoint();
Point2f Translate(const Point2f& p, float dx, float dy);
Point2f Translate(const Point2f& p, const Vector2f& v);
Point2f Scale(const Point2f& p, float sx, float sy);
Point2f Scale(const Point2f& p, const Vector2f& s);
Point2f Rotate(const Point2f& p, float angleDegree);

// Comparaison de points
bool Egal(const Point2f& a, const Point2f& b, float tolerance = 0.0001f);
bool Different(const Point2f& a, const Point2f& b, float tolerance = 0.0001f);

// Conversion
std::string ToString(const Point2f& p);

#endif
```

### **📄 geometry/vector.h**
```cpp
#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include "point.h"

struct Vector2f {
    float x;
    float y;
};

// Création de vecteurs
Vector2f MakeV2f(float x, float y);
Vector2f MakeNullVector();
Vector2f MakeV2f(const Point2f& a, const Point2f& b);

// Opérations algébriques
Vector2f Add(const Vector2f& a, const Vector2f& b);
Vector2f Sub(const Vector2f& a, const Vector2f& b);
Vector2f Scale(const Vector2f& v, float scalar);

// Produits et propriétés
float Dot(const Vector2f& a, const Vector2f& b);
float Length(const Vector2f& v);
Vector2f Normalize(const Vector2f& v);

// Interpolation et opérations avancées
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t);
float Determinant(const Vector2f& a, const Vector2f& b);

// Comparaison de vecteurs
bool Egal(const Vector2f& a, const Vector2f& b, float tolerance = 0.0001f);
bool Different(const Vector2f& a, const Vector2f& b, float tolerance = 0.0001f);

// Conversion
std::string ToString(const Vector2f& v);

#endif
```

### **📄 geometry/utils.h**
```cpp
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

// Templates pour la conversion en string
template<typename T>
std::string ToString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

template<typename T>
std::string ToString(const std::vector<T>& v) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        oss << ToString(v[i]);
        if (i + 1 < v.size()) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

template<typename K, typename V>
std::string ToString(const std::map<K, V>& m) {
    std::ostringstream oss;
    oss << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        oss << ToString(it->first) << ": " << ToString(it->second);
        if (std::next(it) != m.end()) oss << ", ";
    }
    oss << "}";
    return oss.str();
}

// Fonction d'affichage variadique
template<typename T, typename... Args>
void Print(const T& first, const Args&... args) {
    std::cout << ToString(first);
    ((std::cout << ", " << ToString(args)), ...);
    std::cout << std::endl;
}

#endif
```

### **📄 main.cpp** (avec tests unitaires complets)
```cpp
#include "geometry/point.h"
#include "geometry/vector.h"
#include "geometry/utils.h"
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std

### **🧪 TESTS UNITAIRES FROM SCRATCH


void RunTests() {
    cout << "🧪 LANCEMENT DES TESTS UNITAIRES\n" << endl;
    int testsReussis = 0;
    int testsTotal = 0;

    // Macro de test maison
    #define TEST(nom, condition) \
        do { \
            testsTotal++; \
            if (condition) { \
                testsReussis++; \
                cout << "✅ " << nom << endl; \
            } else { \
                cout << "❌ " << nom << " - ÉCHEC" << endl; \
            } \
        } while(0)

    // ==================== TESTS POINTS ====================
    cout << "📍 TESTS DES POINTS" << endl;
    
    // Test création
    Point2f p1 = MakeP2f(2.0f, 3.0f);
    TEST("Création point", p1.x == 2.0f && p1.y == 3.0f);
    
    Point2f zero = MakeNullPoint();
    TEST("Point nul", zero.x == 0.0f && zero.y == 0.0f);
    
    // Test égalité
    Point2f p2 = MakeP2f(2.0f, 3.0f);
    TEST("Égalité points identiques", Egal(p1, p2));
    
    Point2f p3 = MakeP2f(2.00001f, 3.00001f);
    TEST("Égalité avec tolérance", Egal(p1, p3, 0.001f));
    TEST("Différence avec précision", Different(p1, p3, 0.000001f));
    
    // Test translation
    Point2f p4 = Translate(p1, 1.0f, -1.0f);
    Point2f expected1 = MakeP2f(3.0f, 2.0f);
    TEST("Translation point", Egal(p4, expected1));
    
    // Test translation avec vecteur
    Vector2f v = MakeV2f(2.0f, 0.0f);
    Point2f p5 = Translate(p1, v);
    Point2f expected2 = MakeP2f(4.0f, 3.0f);
    TEST("Translation avec vecteur", Egal(p5, expected2));
    
    // Test mise à l'échelle
    Point2f p6 = Scale(p1, 2.0f, 3.0f);
    Point2f expected3 = MakeP2f(4.0f, 9.0f);
    TEST("Mise à l'échelle point", Egal(p6, expected3));
    
    // Test rotation
    Point2f p7 = Rotate(MakeP2f(1.0f, 0.0f), 90.0f);
    Point2f expected4 = MakeP2f(0.0f, 1.0f);
    TEST("Rotation 90°", Egal(p7, expected4, 0.001f));

    // ==================== TESTS VECTEURS ====================
    cout << "\n📐 TESTS DES VECTEURS" << endl;
    
    // Test création
    Vector2f v1 = MakeV2f(3.0f, 4.0f);
    TEST("Création vecteur", v1.x == 3.0f && v1.y == 4.0f);
    
    Vector2f vZero = MakeNullVector();
    TEST("Vecteur nul", vZero.x == 0.0f && vZero.y == 0.0f);
    
    // Test création depuis points
    Vector2f v2 = MakeV2f(MakeP2f(1.0f, 1.0f), MakeP2f(4.0f, 5.0f));
    Vector2f expected5 = MakeV2f(3.0f, 4.0f);
    TEST("Vecteur entre points", Egal(v2, expected5));
    
    // Test addition
    Vector2f v3 = Add(v1, v2);
    Vector2f expected6 = MakeV2f(6.0f, 8.0f);
    TEST("Addition vecteurs", Egal(v3, expected6));
    
    // Test soustraction
    Vector2f v4 = Sub(v1, v2);
    Vector2f expected7 = MakeV2f(0.0f, 0.0f);
    TEST("Soustraction vecteurs", Egal(v4, expected7));
    
    // Test multiplication scalaire
    Vector2f v5 = Scale(v1, 2.0f);
    Vector2f expected8 = MakeV2f(6.0f, 8.0f);
    TEST("Multiplication scalaire", Egal(v5, expected8));
    
    // Test produit scalaire
    Vector2f v6 = MakeV2f(1.0f, 0.0f);
    Vector2f v7 = MakeV2f(0.0f, 1.0f);
    float dot = Dot(v6, v7);
    TEST("Produit scalaire perpendiculaires", dot == 0.0f);
    
    float dot2 = Dot(v6, v6);
    TEST("Produit scalaire même vecteur", dot2 == 1.0f);
    
    // Test longueur
    float len = Length(v1);
    TEST("Longueur vecteur", abs(len - 5.0f) < 0.0001f);
    
    float lenZero = Length(vZero);
    TEST("Longueur vecteur nul", lenZero == 0.0f);
    
    // Test normalisation
    Vector2f v8 = Normalize(v1);
    float lenNorm = Length(v8);
    TEST("Normalisation vecteur", abs(lenNorm - 1.0f) < 0.0001f);
    
    Vector2f v9 = Normalize(vZero);
    TEST("Normalisation vecteur nul", Egal(v9, vZero));
    
    // Test interpolation
    Vector2f v10 = MakeV2f(0.0f, 0.0f);
    Vector2f v11 = MakeV2f(10.0f, 10.0f);
    Vector2f v12 = Lerp(v10, v11, 0.5f);
    Vector2f expected9 = MakeV2f(5.0f, 5.0f);
    TEST("Interpolation linéaire", Egal(v12, expected9));
    
    // Test déterminant
    float det = Determinant(v6, v7);
    TEST("Déterminant vecteurs perpendiculaires", det == 1.0f);

    // ==================== TESTS INTÉGRATION ====================
    cout << "\n🔗 TESTS D'INTÉGRATION" << endl;
    
    // Test transformation complète
    Point2f p = MakeP2f(2.0f, 0.0f);
    Point2f result = Translate(Scale(Rotate(p, 90.0f), 2.0f, 2.0f), 1.0f, 1.0f);
    TEST("Transformation complexe", !Egal(p, result));
    
    // Test cohérence vecteur-point
    Point2f a = MakeP2f(0.0f, 0.0f);
    Point2f b = MakeP2f(3.0f, 4.0f);
    Vector2f ab = MakeV2f(a, b);
    Point2f b_calc = Translate(a, ab.x, ab.y);
    TEST("Cohérence point-vecteur", Egal(b, b_calc));
    
    // Test propriété vecteur nul
    Vector2f nullVec = MakeNullVector();
    Point2f p_unchanged = Translate(p, nullVec);
    TEST("Translation par vecteur nul", Egal(p, p_unchanged));

    // ==================== RAPPORT FINAL ====================
    cout << "\n📊 RAPPORT DES TESTS" << endl;
    cout << "Tests réussis: " << testsReussis << "/" << testsTotal << endl;
    
    if (testsReussis == testsTotal) {
        cout << "🎉 TOUS LES TESTS SONT RÉUSSIS !" << endl;
    } else {
        cout << "⚠️  Certains tests ont échoué" << endl;
    }

    #undef TEST
}

// ============================================================================
// 🎯 FONCTION PRINCIPALE
// ============================================================================

int main() {
    cout << "=========================================" << endl;
    cout << "       📐 MATH - TESTS UNITAIRES" << endl;
    cout << "=========================================" << endl;
    
    RunTests();
    
    cout << "\n=========================================" << endl;
    cout << "           🏁 TESTS TERMINÉS" << endl;
    cout << "=========================================" << endl;
    
    return 0;
}
```

---

## **💡 Ce qu'il faut Retenir**

### **Avantages des Struct sur les Classes**
- **Données publiques** par défaut - accès direct aux coordonnées
- **Sémantique de valeur** - copie simple et prédictible
- **Compatibilité C** - interopérabilité avec d'autres langages
- **Overhead minimal** - pas de coût d'abstraction

### **Concepts Mathématiques Maîtrisés**
- **Algèbre linéaire** 2D appliquée
- **Transformations géométriques** (translation, rotation, scale)
- **Calcul vectoriel** (produit scalaire, normalisation)
- **Interpolation** et transitions

## **🎓 Ce qu'on Apprend en Réalisant ce Projet**

### **Développement avec Struct**
- Organisation de code sans POO
- Fonctions pures sans état
- Gestion de la précision numérique
- Tests unitaires complets

### **Compétences Générales**
- Pensée algorithmique géométrique
- Débogage mathématique
- Validation rigoureuse par tests
- Documentation de code

## **💪 Message d'Encouragement pour les Étudiants**

**Cher étudiant,**

Chaque fonction que vous testez avec succès renforce votre compréhension des mathématiques et de la programmation. Ces concepts de géométrie 2D sont les **fondations** des moteurs graphiques, des jeux vidéo, et des applications de CAO.

Quand vous maîtrisez ces bases, vous ouvrez la porte à la création **d'images, d'animations et de simulations complexes**. Votre code deviendra la **colle entre les mathématiques pures et les applications réelles**.

**Persévérez !** Chaque test réussi est une victoire. Chaque bug résolu vous rend plus fort. Les défis que vous rencontrez aujourd'hui forgent les compétences dont vous aurez besoin demain pour créer les technologies de l'avenir.

## **🎯 Citation Inspirante**

> *"Les mathématiques sont la langue dans laquelle Dieu a écrit l'univers."*  
> **- Galilée**

> *"Dans la vie, rien n'est à craindre, tout est à comprendre."*  
> **- Marie Curie**

---

**Fin du Projet MATH**  
*"Maîtriser les fondations pour construire l'avenir"* 🚀
