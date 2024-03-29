/*******************************************************
 *  is_convertible is a structure, that contains boolean
 *  value, which indicates, that first type is
 *  convertible to the second.
 *
 *  is_convertible_v is just a simplification of usage.
 *
 *  Prameters:
 *      - T1 - first type
 *      - T2 - second type
 *
 *  Return value:
 *      - value == true - T1 is convertible to T2
 *      - value == false - otherwise
 *******************************************************
 *  Author: Firsov Georgy
 *  Contact: gfirsov007@gmail.com
 *  Date: 27.08.2019
 *******************************************************/
#pragma once

template<typename T1, typename T2>
class is_convertible
{
    using Small = char;
    class Big { char m_dummy[2]; };

    /* Don't care about implementation */
    static Small _ConversionTest(const T2&);
    static Big   _ConversionTest(...);
    static T1    _MakeT1();

public:
    static constexpr bool value = ( sizeof(_ConversionTest(_MakeT1())) == sizeof(Small) );
};

template<typename T1, typename T2>
constexpr bool is_convertible_v = is_convertible<T1, T2>::value;
