#ifndef SOFTWAREREVIEW_H
#define SOFTWAREREVIEW_H
#include <QString>

class SoftwareReview
{
public:
    // constructor:
    SoftwareReview(const QString &name, const QString &date, bool recommended);

    // accessors:
    QString getName() const;
    QString getDate() const;
    bool isRecommended() const ;

    // mutators:
    void setName(const QString &name);
    void setRecommended(bool recommended);
    void setDate(const QString &date);

private:
    QString _name;
    QString _date;
    bool _recommended;

};

#endif // SOFTWAREREVIEW_H
