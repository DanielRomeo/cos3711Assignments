#include "softwarereview.h"

// setting private variables using the constructor:
SoftwareReview::SoftwareReview(const QString &name, const QString &date, bool recommended) {
    _name = name;
    _date = date;
    _recommended = recommended;
}

// accessors:
QString SoftwareReview::getName() const{
    return _name;
};
QString SoftwareReview::getDate() const{
    return _date;
};
bool SoftwareReview::isRecommended() const {
    return _recommended;
};

// // mutators:
// void SoftwareReview::setName(const QString &name){
//     _name = name;
// };
// void SoftwareReview::setRecommended(bool recommended){

// };
// void SoftwareReview::(const QString &date);
