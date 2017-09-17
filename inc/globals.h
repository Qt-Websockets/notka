/*
 * globals.h
 *
 * Copyright(C) 2017, Piotr Gregor <piotrgregor@rsyncme.org>
 *
 * Notka Online Clipboard
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */


#ifndef GLOBALS_H
#define GLOBALS_H


#include <QMutexLocker>
#include <QVariant>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "../inc/task.h"


namespace Database {
        extern QMutex mutex;

        bool init_database();
        void close_database();
        int authenticate_user(QString login, QString password);
        bool save_notka(QString user, QByteArray notka);
        bool get_notka(QString user, QByteArray &notka);

        class DbReconnectTask : public PeriodicTask {
        public:
                DbReconnectTask(int interval_ms);
                ~DbReconnectTask();
        private:
                bool reconnect();
                bool run_once() override { return reconnect(); }
        };
}

namespace Db = Database;

#endif // GLOBALS_H
