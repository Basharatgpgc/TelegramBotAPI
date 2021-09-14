#include "Types/LoginURL.h"

#include "qjsonobject.h"

Telegram::LoginURL::LoginURL() :
	url(""),
	forward_text(std::nullopt),
	bot_username(std::nullopt),
	request_write_access(std::nullopt)
{}

Telegram::LoginURL::LoginURL(const QString& url,
							 const std::optional<QString>& forward_text,
							 const std::optional<QString>& bot_username,
							 const std::optional<bool>& request_write_access) :
	url(url),
	forward_text(forward_text),
	bot_username(bot_username),
	request_write_access(request_write_access)
{}

Telegram::LoginURL::LoginURL(const QJsonObject& jsonObject)
{
	jsonObject.contains("url")					? url = jsonObject["url"].toString()								 : url = "";
	jsonObject.contains("forward_text")			? forward_text = jsonObject["forward_text"].toString()				 : forward_text = std::nullopt;
	jsonObject.contains("bot_username")			? bot_username = jsonObject["bot_username"].toString()				 : bot_username = std::nullopt;
	jsonObject.contains("request_write_access") ? request_write_access = jsonObject["request_write_access"].toBool() : request_write_access = std::nullopt;
}

QJsonObject Telegram::LoginURL::toObject() const
{
	if(isEmpty())
		return QJsonObject();

	QJsonObject loginURLJsonObject{ {"url", url} };

	if (forward_text.has_value())			loginURLJsonObject.insert("forward_text", *forward_text);
	if (bot_username.has_value())			loginURLJsonObject.insert("bot_username", *bot_username);
	if (request_write_access.has_value())	loginURLJsonObject.insert("request_write_access", *request_write_access);

	return loginURLJsonObject;
}

bool Telegram::LoginURL::isEmpty() const
{
	return url == ""
		   and forward_text == std::nullopt
		   and bot_username == std::nullopt
		   and request_write_access == std::nullopt;
}
