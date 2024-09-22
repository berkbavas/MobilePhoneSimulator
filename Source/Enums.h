#ifndef ENUMS_H
#define ENUMS_H

namespace Enums {

enum class Button : int { //
    Zero,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Star,
    Square,
    Clear,
    Enter,
    Up,
    Down,
    None
};

enum class Action { //
    Pressed,
    Released,
    Clicked
};

} // namespace Enums

#endif // ENUMS_H
