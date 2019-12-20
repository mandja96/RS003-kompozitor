#ifndef KOMPOZITOR_TRACKS_LIST_MODEL_HPP
#define KOMPOZITOR_TRACKS_LIST_MODEL_HPP

#include <QtCore/QAbstractListModel>
#include "track_note.hpp"

class TracksListModel: public QAbstractListModel {

Q_OBJECT

public:
    enum RoleType {
        TRACK_DATA = Qt::UserRole + 1,
        TRACK_NUMBER,
        TRACK_TYPE
    };

    explicit TracksListModel(QObject* parent = nullptr) {};

    [[nodiscard]]
    int rowCount(const QModelIndex &parent) const override;

    [[nodiscard]]
    int columnCount(const QModelIndex &parent) const override;

    [[nodiscard]]
    QVariant data(const QModelIndex &index, int role) const override;

    [[nodiscard]]
    QHash<int, QByteArray> roleNames() const override;

private:
    // Temporary data for testing
    std::vector<QList<QObject*>> _data {
        QList<QObject*> {
                new TrackNote(2, 0, 2),
                new TrackNote(5, 3, 4)
        },
        QList<QObject*> {
                new TrackNote(3, 0, 2),
                new TrackNote(5, 2, 5),
                new TrackNote(2, 4, 6),
                new TrackNote(7, 7, 10)
        }
    };
};

#endif //KOMPOZITOR_TRACKS_LIST_MODEL_HPP
