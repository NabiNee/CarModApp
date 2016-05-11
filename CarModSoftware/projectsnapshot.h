/* This displays the overall stats of the project when a user is done. Ideally, this would be what is saved/loaded, since it contains all
 * the information in one place. This would be visible/selectable from user profile screen.*/
#ifndef PROJECTSNAPSHOT_H
#define PROJECTSNAPSHOT_H

#include <QDialog>
#include <QString>

namespace Ui {
class ProjectSnapshot;
}

class ProjectSnapshot : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectSnapshot(QWidget *parent = 0);
    ~ProjectSnapshot();
    void passData(QString car, QString modL, QString modW, QString modH, QString modE, float price, QPixmap, QPixmap, QPixmap, QPixmap);

private:
    Ui::ProjectSnapshot *ui;
};

#endif // PROJECTSNAPSHOT_H
