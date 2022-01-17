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
    Space,
    Up,
    Down
};

enum class ActionType { //
    Pressed,
    Released,
    Clicked
};

} // namespace Enums

#endif // ENUMS_H
