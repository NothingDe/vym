#include "scripting.h"

#include "vymmodel.h"
#include "mainwindow.h"

extern Main *mainWindow;

VymModelWrapper::VymModelWrapper(VymModel *m)
{
    model = m;
}

void VymModelWrapper::addBranch(int pos)
{
    BranchItem *selbi = model->getSelectedBranch();
    if (selbi)
        model->addNewBranch(selbi, pos);
}

void VymModelWrapper::setHeadingPlainText(const QString &s)
{
    model->setHeading(s);
}

QString VymModelWrapper::getHeadingPlainText()
{
    return model->getHeading().getTextASCII(); //FIXME-2 testing
}

QString VymModelWrapper::getFileName()
{
    return model->getFileName();
}

///////////////////////////////////////////////////////////////////////////
VymWrapper::VymWrapper()
{
}

void VymWrapper::toggleTreeEditor()
{
    mainWindow->windowToggleTreeEditor();
}

QObject* VymWrapper::getCurrentMap()
{
    // http://doc.qt.io/qt-5/qtscript-index.html#making-a-c-object-available-to-scripts-written-in-qt-script
    return mainWindow->getCurrentModelWrapper();
}

void VymWrapper::selectMap(uint n)
{
    if ( !mainWindow->gotoWindow( n ))
    {
        // FIXME-0 throw error
        // QScriptContext::throwError( QScriptContext::RangeError, QString("No map '%1' available-").arg(n) );
    }


}

