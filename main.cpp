/* *************DOC***************
 * This demonstrates that a derived class constructor doesn't
 * need to do anything, the base class constructor is
 * automatically invoked.
 *
 * And whatever the base class constructor does, the derived
 * class constructor does it too, even if the derived class
 * constructor does other stuff, it'll do the base stuff first.
 *
 * Only the constructor does this. If I write another print() in
 * the derived class, it only does what is in the definition in
 * the derived class.
 * *******************************/
#include <cstdio>

class mDotEvent
{
public:
    mDotEvent(void) : a(3){printf("Made a base, use default for a.\n");}
    void print(void) const { printf("%d", a); }
private:
    int a;

};

class RadioEvent : public mDotEvent
{
public:
    RadioEvent(void) : b(4) {printf("Made a derived, use default for b.\n");}
    RadioEvent(int x) : b(x) {printf("Made a derived, take int for b.\n");}
    void print(void) const { mDotEvent::print(); printf(", %d", b); }
private:
    int b;
};

int main()
{
    printf("\nmDotEvent base_event;\n");
    mDotEvent base_event;
    // Made a base, use default for a.

    printf("base_event.print(): "); base_event.print(); printf("\n");
    // base_event.print(): 3

    printf("\nRadioEvent derived_event;\n");
    RadioEvent derived_event;
    // Made a base, use default for a.
    // Made a derived, use default for b.

    printf("derived_event.print(): "); derived_event.print(); printf("\n");
    // derived_event.print(): 3, 4

    printf("\nRadioEvent d_event(5);\n");
    RadioEvent d_event(5);
    // Made a base, use default for a.
    // Made a derived, take int for b.

    printf("d_event.print(): "); d_event.print(); printf("\n");
    // d_event.print(): 3, 5
}
