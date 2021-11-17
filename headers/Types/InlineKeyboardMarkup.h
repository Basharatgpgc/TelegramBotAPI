#ifndef TELEGRAM_TYPES_INLINEKEYBOARDMARKUP_H
#define TELEGRAM_TYPES_INLINEKEYBOARDMARKUP_H

#include "qvector.h"

#include "InlineKeyboardButton.h"

namespace Telegram
{
    /**
     *
     * @brief This struct represents an inline keyboard that appears right next to the message it belongs to
     *
     * > **Note:** This will only work in Telegram versions released after 9 April, 2016. Older clients will display unsupported message
     *
     */

    struct InlineKeyboardMarkup
    {
        /** @brief Default constructor. Constructs an empty InlineKeyboardMarkup object */
        InlineKeyboardMarkup();

        /** @brief Constructs InlineKeyboardMarkup object from parameters */
        InlineKeyboardMarkup(const QVector<QVector<InlineKeyboardButton>>& inline_keyboard);

        /** @brief JSON constructor. Constructs InlineKeyboardButton object from QJsonObject
         *
         * QJsonObject which is passed to constuctor has to has JSON array of JSON array of InlineKeyboardMarkup objects to construct correct object, otherwise empty InlineKeyboardMarkup object will be constructed */
        InlineKeyboardMarkup(const QJsonObject& jsonObject);

        /* @brief Returns InlineKeyboardMarkup in form of JSON object. Returns empty QJsonObject if InlineKeyboardMarkup is empty */
        QJsonObject toObject() const;

        /* @brief Returns true if InlineKeyboardMarkup is empty */
        bool isEmpty() const;

//** Fields **//

        /** @brief QVector of button rows, each represented by a QVector of InlineKeyboardButton objects */
        QVector<QVector<InlineKeyboardButton>> inline_keyboard;
    };
}

#endif // TELEGRAM_TYPES_INLINEKEYBOARDMARKUP_H
