#ifndef TELEGRAM_TYPES_INLINEQUERYRESULTPHOTO_H
#define TELEGRAM_TYPES_INLINEQUERYRESULTPHOTO_H

#include <optional>

#include "qstring.h"
class QJsonObject;

namespace Telegram { class InputMessageContent; }
#include "Types/InlineQueryResult.h"
#include "Types/InlineKeyboardMarkup.h"
#include "Types/MessageEntity.h"

namespace Telegram
{
    /**
    *
    * @brief This struct represents a link to a photo. By default, this photo will be sent by the user with optional caption. Alternatively, you can use input_message_content to send a message with the specified content instead of the photo
    *
    */

    struct InlineQueryResultPhoto : public InlineQueryResult
    {
        /** @brief Default constructor. Constructs an empty InlineQueryResultPhoto object
         *
         * All fields setted to 0, "", etc... All optional fields setted to std::nullopt */
        InlineQueryResultPhoto();

        /** @brief Constructs InlineQueryResultPhoto object from parameters */
        InlineQueryResultPhoto(const QString& id,
                               const QString& photo_url,
                               const QString& thumb_url,
                               const std::optional<qint32>& photo_width = std::nullopt,
                               const std::optional<qint32>& photo_height = std::nullopt,
                               const std::optional<QString>& title = std::nullopt,
                               const std::optional<QString>& description = std::nullopt,
                               const std::optional<QString>& caption = std::nullopt,
                               const std::optional<QString>& parse_mode = std::nullopt,
                               const std::optional<QVector<MessageEntity>>& caption_entities = std::nullopt,
                               const std::optional<InlineKeyboardMarkup>& reply_markup = std::nullopt,
                               const std::optional<std::shared_ptr<InputMessageContent>>& input_message_content = std::nullopt);

        /* @brief Returns InlineQueryResultPhoto in form of JSON object. Returns empty QJsonObject if InlineQueryResultPhoto is empty */
        virtual QJsonObject toObject() const override;

        /* @brief Returns true if InlineQueryResultPhoto is empty */
        virtual bool isEmpty() const override;

//** Fields **//

        /** @brief Type of the result, must be photo */
        const QString type = "photo";

        /** @brief Unique identifier for this result, 1-64 Bytes */
        QString id;

        /** @brief A valid URL of the photo. Photo must be in jpeg format. Photo size must not exceed 5MB */
        QString photo_url;	         
        
        /** @brief URL of the thumbnail for the photo */
        QString thumb_url;
        
        /** @brief Optional. Width of the photo */
        std::optional<qint32> photo_width;
        
        /** @brief Optional. Height of the photo */
        std::optional<qint32> photo_height;
        
        /** @brief Optional. Title for the result */
        std::optional<QString> title;
        
        /** @brief Optional. Short description of the result */
        std::optional<QString> description;
        
        /** @brief Optional. Caption of the photo to be sent, 0-1024 characters after entities parsing */
        std::optional<QString> caption;
        
        /** @brief Optional. Mode for parsing entities in the photo caption. See formatting options for more details. */
        std::optional<QString> parse_mode;
        
        /** @brief Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode */
        std::optional<QVector<MessageEntity>> caption_entities;
        
        /** @brief Optional. Inline keyboard attached to the message */
        std::optional<InlineKeyboardMarkup> reply_markup;
        
        /** @brief Optional. Content of the message to be sent instead of the photo */
        std::optional<std::shared_ptr<InputMessageContent>> input_message_content;
    };
}

#endif // TELEGRAM_TYPES_INLINEQUERYRESULTPHOTO_H
