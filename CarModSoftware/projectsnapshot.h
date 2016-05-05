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
    void passData(QString car,QString modL, QString modW, QString modH, QString modE, float price);

private:
    Ui::ProjectSnapshot *ui;
};

#endif // PROJECTSNAPSHOT_H
