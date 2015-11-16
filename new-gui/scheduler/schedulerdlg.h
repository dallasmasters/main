#ifndef SCHEDULERDLG_H
#define SCHEDULERDLG_H


#include "ui_schedulerdlg.h"


class SchedulerDlg : public QDialog, private Ui::SchedulerDlg
{
    Q_OBJECT

    // types

    // static data members

    static const int32_t smSCHEDULER_TIMER_INTERVAL = 30000;
    static const int32_t smCHECK_CONFIGFILE_TIMER_INTERVAL = 5000;

    // instance data members

    bool mIsDialog = false;

public:
    explicit SchedulerDlg(QWidget *parent = 0);
};

#endif // SCHEDULERDLG_H